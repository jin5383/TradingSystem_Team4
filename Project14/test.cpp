#include "nemo_api.cpp"
#include "kiwer_api.cpp"
#include "gmock/gmock.h"
#include "application.cpp"

using namespace testing;
using std::cout;

TEST(TradingSystem, selectMock)
{
	TradingSystem system;

	std::stringstream buffer;
	std::streambuf* old_buffer = std::cout.rdbuf(buffer.rdbuf());

	system.selectStockerBrocker(MOCK);

	std::cout.rdbuf(old_buffer);

	EXPECT_THAT(buffer.str(), HasSubstr("Select Mock Brocker"));
}