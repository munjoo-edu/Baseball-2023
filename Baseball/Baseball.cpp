#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& q)
		: question(q)
	{
		
	}
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

	int getCountMatchedChar(const string& guessNumber)
	{
		int match_cnt = 0;
		for(int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == question[i])
				match_cnt++;
		}
		return match_cnt;
	}

	GuessResult guess(const string& guessNumber)
	{
		CheckParameter(guessNumber);
		if(guessNumber == question)
			return { true, 3, 0 };

		return { false,
			getCountMatchedChar(guessNumber),
			getCountMatchedChar(guessNumber) == 1 ? 2 : 0 };
	}

private:
	string question;
};