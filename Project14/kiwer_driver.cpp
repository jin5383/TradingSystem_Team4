#include "stocker_brocker.h"
#include "kiwer_api.cpp"

class KiwerAdapter : public StockerBrocker {
public:
	KiwerAdapter(KiwerAPI* kiwer) {
		m_kiwer = kiwer;
	}
	void login(string ID, string password) {
		m_kiwer->login(ID, password);
	}
	void buy(string stockCode, int count, int price) { 
		m_kiwer->buy(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) { 
		m_kiwer->sell(stockCode, count, price);
	}
	int getPrice(string stockCode) {
		return m_kiwer->currentPrice(stockCode);
	};

private:
	KiwerAPI* m_kiwer;
};
