#include "LongArithmetic.h"

Longi::Longi(void)
{};

Longi::Longi(const Longi& l)
{
	this->number.insert(this->number.end(), l.number.begin(), l.number.end());
}
Longi::Longi(int size)
{
	for (int i = 0; i < size; i++)
		this->number.push_back(0);
}
Longi Longi::operator= (const Longi& l)
{
	this->number.clear();
	this->number.insert(this->number.end(), l.number.begin(), l.number.end());
	return *this;
}

istream& operator>>(istream& in, Longi& l)
{
	string StringNumber;
	in >> StringNumber;

	l.number.clear();
	for (int i = StringNumber.length() - 1; i >= 0 ; i--)
	{
		l.number.push_back(StringNumber[i]-'0');
	}

	return in;
}

ostream& operator<<(ostream &out, Longi &l)
{
	int t;
	for (int i = l.number.size()-1; i >= 0; i--)
	{
		t = l.number[i];
		out << t;
	}
	return out;
}

Longi operator+(Longi &first, Longi &second)
{
	Longi answer;
	int remainder = 0;
	
	for(int i = 0; i < max(first.number.size(),second.number.size()); i++)
	{
		remainder += i < first.number.size() ? first.number[i] : 0;
		remainder += i < second.number.size() ? second.number[i] : 0;

		answer.number.push_back(remainder % 10);
		remainder /= 10;
	}
	if (remainder) answer.number.push_back(remainder);
	
	
	return answer;
}
Longi operator-(Longi &first, Longi &second)
{
	Longi answer;
	for(int i=0; i<second.number.size();i++)
	{
		//if we can't substract
		if(first.number[i] < second.number[i])
		{
			int j = i + 1;
			while(first.number[j]==0)
			{
				j++;
			}
			for(int k = j; j>i;j--)
			{
				first.number[j]--;
				first.number[j - 1] += 10;
			}
		}
		answer.number.push_back(first.number[i] - second.number[i]);
	}
	for (int i = second.number.size(); i < first.number.size(); i++) answer.number.push_back(first.number[i]);
	//deleting 0 at the begining
	while (answer.number.size() > 1 && answer.number.back() == 0)
		answer.number.pop_back();
	return answer;
}
Longi operator*(Longi &first, int second)
{
	Longi answer(first);
	int remainder = 0;
	for(int i=0;i < answer.number.size() ||  remainder;i++)
	{
		if (i == answer.number.size())
			answer.number.push_back(0);
		long long current = remainder + answer.number[i] * second;
		answer.number[i] = (int) current % 10;
		remainder = (int)current / 10;

	}
	while (answer.number.size() > 1 && answer.number.back() == 0)
		answer.number.pop_back();
	return answer;
}
Longi operator*(Longi &first, Longi &second)
{
	Longi answer(first.number.size() + second.number.size());
	
	for (int i = 0; i<first.number.size(); ++i)
		for (int j = 0, carry = 0; j<(int)second.number.size() || carry; ++j) {
			long long cur = answer.number[i + j] + first.number[i] * (j < (int)second.number.size() ? second.number[j] : 0) + carry;
			answer.number[i + j] = int(cur % 10);
			carry = int(cur / 10);
		}
	while (answer.number.size() > 1 && answer.number.back() == 0)
		answer.number.pop_back();
	return answer;
}

