#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Longi
{
private:

	vector<int> number;
	friend istream& operator>>(istream &in, Longi &l);
	friend ostream& operator<<(ostream &out, Longi &l);
	friend Longi operator+(Longi &first, Longi &second);
	friend Longi operator-(Longi &first, Longi &second);
	friend Longi operator*(Longi &first, Longi & second);
	friend Longi operator*(Longi &first, int second);

public:
	Longi(void);
	Longi(const Longi& l);
	Longi(int a);
	Longi operator=(const Longi& l);

};