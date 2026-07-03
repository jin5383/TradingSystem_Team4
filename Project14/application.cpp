#include <vector>
#include <windows.h>
#include "stocker_brocker.h"
#include <vector>
#include "nemo_driver.cpp"
#include "kiwer_driver.cpp"
#include "mock_driver.cpp"

using namespace std;

class BrockerFactory {
public:
	static StockerBrocker* getStockerBrocker(string brocker) {
		if (brocker == KIWER) {
//			KiwerAPI kiwerAPI;
//			return new KiwerAdapter(kiwerAPI);
		}
		if (brocker == NEMO) {
			NemoAPI  nemoAPI;
			return new NemoAdapter(nemoAPI, 10);
		}
		if (brocker == MOCK) {
//			MockAPI  mockAPI;
//			return new MockAdapter(mockAPI);
		}
		return nullptr;
	}
};

class TradingSystem {
public:
	const static int PRICE_CHECK_INTERVAL_MS = 200;
	const static int PRICE_CHECK_COUNT = 3;

	void selectStockerBrocker(string brocker) {
		stocker = BrockerFactory::getStockerBrocker(brocker);
	}
	void selectStockerBrodker(StockerBrocker* stocker) {
		this->stocker = stocker;
	}
	void login(string ID, string password) {
		stocker->login(ID, password);
	}
	void buy(string stockCode, int count, int price) {
		stocker->buy(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) {
		//KKH
		if (!stocker) return;
		stocker->sell(stockCode, count, price);
	}
	int getPrice(string stockCode) {
		//KKH
		if (!stocker) return 0;
		return stocker->getPrice(stockCode);
	}

	void buyNiceTiming(string stockCode, int totalAmount) {
		//KKH
		std::vector<int> prices = readPriceTrend(*stocker, stockCode);
		if (!isUptrend(prices)) {
			return;
		}

		int lastPrice = prices.back();
		int count = totalAmount / lastPrice;
		if (count <= 0) {
			return;
		}

		buy(stockCode, count, lastPrice);
	}
	void sellNiceTiming(string stockCode, int count) {
		//HSJ
		vector<int> price;
		for (int i = 0; i < 3;i++) {
			price.push_back(stocker->getPrice(stockCode));
			// sleep 200ms
		}

		if (price[0] > price[1] && price[1] > price[2]) {
			stocker->buy(stockCode, count, price[2]);
		}
	}
	void selectStockerBrockerMock(StockerBrocker* brocker) {
		stocker = brocker;
	}
private:
	StockerBrocker* stocker;

	std::vector<int> readPriceTrend(StockerBrocker& driver, const std::string& stockCode) {
		std::vector<int> prices;

		for (int i = 0; i < PRICE_CHECK_COUNT; ++i) {
			if (i > 0) {
				Sleep(PRICE_CHECK_INTERVAL_MS);
			}
			prices.push_back(driver.getPrice(stockCode));
		}
		return prices;
	}

	bool isUptrend(const std::vector<int>& prices) {
		if (prices.size() < PRICE_CHECK_COUNT) {
			return false;
		}

		return prices[0] < prices[1] && prices[1] < prices[2];
	}
};