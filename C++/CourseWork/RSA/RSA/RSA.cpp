// RSA.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "LongArithmetic.h"


int main()
{
	Longi a;
	Longi b;
	cin >> a;
	cin >> b;
	int c = 100000;
	b = a * b;
	cout << b;
	return 0;
}

