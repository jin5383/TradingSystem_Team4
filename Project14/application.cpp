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
	void selectStockerBrocker(string brocker) {
		stocker = BrockerFactory::getStockerBrocker(brocker);
	}
	void login(string ID, string password) {
		stocker->login(ID, password);
	}
	void buy(string stockCode, int count, int price) {
		stocker->buy(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) {
		//KKH
	}
	int getPrice(string stockCode) {
		//KKH
		return 0;
	}
	void buyNiceTiming(string stockCode, int price) {
		//KKH
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
		//select API
		//RJH

	}
private:
	StockerBrocker* stocker;
};