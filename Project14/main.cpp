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
	ts.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = ts.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, getPrice("Code"))
		.Times(3);
	ts.buyNiceTiming("Code", 10);

}

TEST(Trading, Apptest1)
{
	TradingSystem ts;
	ts.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = ts.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, getPrice("Code"))
		.Times(3);
	ts.sellNiceTiming("Code", 10);

}


TEST(NemoDriverTest, login)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(NEMO);
	system.login("NemoNotSemo", "31415926535");

	cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("[NEMO]NemoNotSemo login GOOD\n"));
}