#ifndef Longi_h
#define Longi_h

#include <stdio.h>
#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Longi
{
private:
	vector<int> m;
public:
	
	Longi();
	Longi(int size);
	Longi(const Longi& l);
	Longi operator=(const Longi& l);
	friend istream& operator >> (istream &is, Longi &l);
	friend ostream& operator<<(ostream &os, const Longi &l);
	friend Longi operator+(const Longi &l1, const Longi &l2);


	int toInt(Longi &a);

	friend bool operator<(Longi &a, Longi &b);
	friend bool operator==(Longi &a, Longi &b);
	friend Longi operator-(Longi l1, Longi l2);
	friend Longi operator*(Longi a, Longi b);
	friend Longi operator*(Longi a, int b);
	friend Longi operator/(Longi a, int b);
	friend Longi operator/(Longi left, Longi right);
	void _shift_right();
	Longi clear();
	
};

#endif /* Longi_hpp */
