#include "nemo_api.cpp"
#include "kiwer_api.cpp"
#include "gmock/gmock.h"
using namespace testing;

int main(void)
{
	InitGoogleMock();

	return RUN_ALL_TESTS();
}