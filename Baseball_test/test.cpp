#include "pch.h"
#include "..\Baseball\Baseball.cpp"
using namespace std;

TEST(TestBaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}