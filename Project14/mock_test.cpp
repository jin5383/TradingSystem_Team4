#include "nemo_api.cpp"
#include "kiwer_api.cpp"
#include "gmock/gmock.h"
#include "application.cpp"

using namespace testing;
using std::cout;

TEST(TradingSystemDefault, selectMock)
{
	TradingSystem system;
	system.selectStockerBrocker(MOCK);

	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_NE(mockBrocker, nullptr);
}

TEST(TradingSystemDefault, MockLoginSucess)
{
	TradingSystem system;
	system.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, login(_, _))
		.Times(1);

	system.login("mincoding", "1234");
}

TEST(TradingSystemDefault, MockBuySuccess)
{
	TradingSystem system;
	system.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, buy(_, _, _))
		.Times(1);

	system.buy("005930", 1000, 10);
}

TEST(TradingSystemDefault, MockSellSuccess)
{
	TradingSystem system;
	system.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, sell(_, _, _))
		.Times(1);

	system.sell("005930", 1000, 10);
}

TEST(TradingSystemDefault, MockgetPrice)
{
	TradingSystem system;
	int expected_price = 500000;
	int actual_price;

	system.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, getPrice(_))
		.Times(1)
		.WillRepeatedly(Return(500000));

	actual_price = system.getPrice("005930");

	EXPECT_EQ(expected_price, actual_price);
}

TEST(TradingSystemDefault, buyNiceTiming)
{
	TradingSystem system;
	int expected_price = 300000;
	int actual_price;

	system.selectStockerBrocker(MOCK);
	StockerBrocker* currentBrocker = system.getBrocker();
	StockerBrockerMock* mockBrocker = dynamic_cast<StockerBrockerMock*>(currentBrocker);

	EXPECT_CALL(*mockBrocker, getPrice(_))
		.Times(3)
		.WillOnce(Return(1000))
		.WillOnce(Return(2000))
		.WillOnce(Return(3000));

	EXPECT_CALL(*mockBrocker, buy("AAA", 100, 3000))
		.Times(1);

	system.buyNiceTiming("AAA", expected_price);
}