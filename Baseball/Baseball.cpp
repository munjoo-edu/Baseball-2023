#include <stdexcept>

using namespace std;

class Baseball
{
public:
	bool isDupNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void CheckParameter(const string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDupNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	void guess(const string& guessNumber)
	{
		CheckParameter(guessNumber);
	}
};