#include "stocker_brocker.h"

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
	}
	void buyNiceTiming() {
		//KKH
	}
	void sellNiceTining() {
		//HSJ
	}
private:
	StockerBrocker* stocker;
};