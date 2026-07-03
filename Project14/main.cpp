#include "application.cpp"
#include "gmock/gmock.h"
#include <string>
using std::string;
using namespace testing;

int main(void)
{
	InitGoogleMock();

	return RUN_ALL_TESTS();
}


TEST(Trading, Apptest0)
{
	TradingSystem ts;
	StockerBrockerMock brocker;
	ts.selectStockerBrockerMock(&brocker);
	EXPECT_CALL(brocker, getPrice("Code"))
		.Times(3);
	ts.buyNiceTiming("Code", 10);

}

TEST(Trading, Apptest1)
{
	TradingSystem ts;
	StockerBrockerMock brocker;
	ts.selectStockerBrockerMock(&brocker);
	EXPECT_CALL(brocker, getPrice("Code"))
		.Times(3);
	ts.sellNiceTiming("Code", 10);

}