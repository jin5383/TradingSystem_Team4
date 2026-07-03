#include "nemo_api.cpp"
#include "kiwer_api.cpp"
#include "gmock/gmock.h"
#include "application.cpp"

using namespace testing;
using std::cout;

TEST(TradingSystemDefault, selectMock)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(MOCK);

	cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("Select Mock Brocker"));
}

TEST(TradingSystemDefault, MockLoginSucess)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(MOCK);
	system.login("mincoding", "1234");

	cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("[Mock] Login Success"));
}

TEST(TradingSystemDefault, MockBuySuccess)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(MOCK);
	system.buy("005930", 1000, 10);

	cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("buy"));
	EXPECT_THAT(buffer.str(), HasSubstr("code: 005930"));
	EXPECT_THAT(buffer.str(), HasSubstr("price: 1000"));
	EXPECT_THAT(buffer.str(), HasSubstr("count: 10"));
}

TEST(TradingSystemDefault, MockSellSuccess)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(MOCK);
	system.sell("005930", 1000, 10);

	cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("sell"));
	EXPECT_THAT(buffer.str(), HasSubstr("code: 005930"));
	EXPECT_THAT(buffer.str(), HasSubstr("price: 1000"));
	EXPECT_THAT(buffer.str(), HasSubstr("count: 10"));
}

TEST(TradingSystemDefault, MockgetPrice)
{
	TradingSystem system;
	int expected_price = 500000;
	int actual_price;

	system.selectStockerBrocker(MOCK);
	actual_price = system.getPrice("005930");

	EXPECT_EQ(expected_price, actual_price);
}
