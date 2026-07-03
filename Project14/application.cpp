#include "stocker_brocker.h"
#include <vector>

using namespace std;

class BrockerFactory {
public:
	StockerBrocker getStockerBrocker(string brocker) {
		//
	}
};

class TradingSystem {
public:
	void selectStockerBrocker(string brocker) {
		//select API
		//RJH
	}
	void login(string ID, string password) {
		//RJH
	}
	void buy(string stockCode, int count, int price) {
		//RJH
	}
	void sell(string stockCode, int count, int price) {
		//KKH
	}
	int getPrice(string stockCode) {
		//KKH
		return 0;
	}
	void buyNiceTiming() {
		//KKH
	}
	void sellNiceTining(string stockCode, int count) {
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
private:
	StockerBrocker* stocker;
};