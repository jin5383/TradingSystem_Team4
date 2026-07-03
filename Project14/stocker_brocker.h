#include <string>
using std::string;
#define interface struct

const string NEMO = "nemo";
const string KIWER = "kiwer";

interface StockerBrocker {
	virtual void login(string ID, string password);
	virtual void buy(string stockCode, int count, int price);
	virtual void sell(string stockCode, int count, int price);
	virtual int getPrice(string stockCode);
};
