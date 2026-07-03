#ifndef STOCK_BROCKER_H
#define STOCK_BROCKER_H

#include "gmock/gmock.h"

using namespace testing;
#include <string>
using std::string;
#define interface struct

const string NEMO = "nemo";
const string KIWER = "kiwer";
const string MOCK = "mock";


interface StockerBrocker {
	virtual ~StockerBrocker() = default;
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int count, int price) = 0;
	virtual void sell(string stockCode, int count, int price) = 0;
	virtual int getPrice(string stockCode) = 0;
};


class StockerBrockerMock : public StockerBrocker {
public:
	MOCK_METHOD(void, login, (std::string ID, string password), (override));
	MOCK_METHOD(void, buy, (std::string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sell, (std::string stockCode, int count, int price), (override));
	MOCK_METHOD(int, getPrice, (std::string stockCode), (override));
};

#endif // STOCK_BROCKER_H
