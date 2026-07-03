#include "stocker_brocker.h"
#include "kiwer_api.cpp"

class KiwerAdapter : public StockerBrocker {
public:
	KiwerAdapter(KiwerAPI* kiwer) {
		if (kiwer == nullptr) {
			throw std::invalid_argument("KiwerAdapter: kiwer must not be null");
		}
		m_kiwer = kiwer;
	}
	void login(string ID, string password) override {
		m_kiwer->login(ID, password);
	}
	void buy(string stockCode, int count, int price) override {
		m_kiwer->buy(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) override {
		m_kiwer->sell(stockCode, count, price);
	}
	int getPrice(string stockCode) override {
		return m_kiwer->currentPrice(stockCode);
	}

private:
	KiwerAPI* m_kiwer;
};
