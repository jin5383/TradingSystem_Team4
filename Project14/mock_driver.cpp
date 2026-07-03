#include "stocker_brocker.h"

class MockAdapter : public StockerBrocker {
	void login(string ID, string password) {}
	void buy(string stockCode, int count, int price) {}
	void sell(string stockCode, int count, int price) {}
	int getPrice(string stockCode) { return 0; }
};