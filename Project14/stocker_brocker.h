#ifndef STOCK_BROCKER_H
#define STOCK_BROCKER_H

#include <string>
using std::string;
#define interface struct

const string NEMO = "nemo";
const string KIWER = "kiwer";
const string MOCK = "mock";

interface StockerBrocker {
	virtual void login(string ID, string password);
	virtual void buy(string stockCode, int count, int price);
	virtual void sell(string stockCode, int count, int price);
	virtual int getPrice(string stockCode);
};

#endif // STOCK_BROCKER_H
