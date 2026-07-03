#include "stocker_brocker.h"
#include "nemo_api.cpp"

class NemoAdapter : public StockerBrocker {
public:
	explicit NemoAdapter(NemoAPI& nemoAPI, int minute) : nemoAPI_(nemoAPI), minute_(minute) {}
	void login(string ID, string password) {
		nemoAPI_.certification(ID, password);
	}
	void buy(string stockCode, int count, int price) {
		nemoAPI_.purchasingStock(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) {
		nemoAPI_.sellingStock(stockCode, count, price);
	}
	int getPrice(string stockCode) {
		nemoAPI_.getMarketPrice(stockCode, minute_);
	}

private:
	NemoAPI& nemoAPI_;
	int minute_;
};