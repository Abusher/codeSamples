#include "Longi.h"


Longi::Longi()
{
	m.clear();
}
Longi::Longi(int size)
{
	m.resize(size);
}
Longi::Longi(const Longi& l)
{
	this->m.insert(this->m.end(), l.m.begin(), l.m.end());
}
Longi Longi::operator=(const Longi& l)
{
	this->m.insert(this->m.end(), l.m.begin(), l.m.end());
	return *this;
}

int Longi::toInt(Longi &a) {
	int __int = 0;
	for (int j = a.m.size(); j >= 0; --j)
	{
		__int += a.m[j] * pow(10, j);
	}

	return __int;
}
Longi Longi::clear() {
	while (this->m.size() > 0)
		this->m.pop_back();
	return *this;

}
bool operator==(Longi &a, Longi &b) {
	if (a.m.size() == b.m.size()) {
		for (int i = 0; i <= a.m.size() - 1; i++) {
			if (a.m[i] != b.m[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}


}

bool operator<(Longi &a, Longi &b) {
	if (a.m.size()>b.m.size()) {
		return false;
	}
	else if (a.m.size()<b.m.size()) {
		return true;
	}
	else if (a.m.size() == b.m.size()) {

		for (int i = a.m.size() - 1; i >= 0; i--) {
			if (a.m[i]>b.m[i]) {
				return false;
			}
			if (a.m[i]<b.m[i]) {
				return true;
			}
		}
		if (a == b) { return false; }
		return true;
	}
	return false;
}
istream& operator >> (istream &is, Longi &l)
{
	char s[1000];
	cin >> s;
	for (int j = strlen(s) - 1; j >= 0; --j)
		l.m.push_back(s[j] - '0');
	return is;
}
ostream& operator<<(ostream &os, const Longi &l)
{
	int t;
	for (int j = l.m.size() - 1; j >= 0; --j)
	{
		t = l.m[j];
		os << t;
	}
	return os;
}

int max(int x, int y)
{
	return (x >= y) ? x : y;
}
Longi operator+(const Longi &l1, const Longi &l2)
{
	Longi temp;
	int r = 0;
	int n = max(l1.m.size(), l2.m.size());

	for (int j = 0; j<n; j++)
	{
		int t1, t2;
		if (j<l1.m.size() && j<l2.m.size())
		{
			t1 = l1.m[j]; t2 = l2.m[j];
			r += (t1 + t2);
		}
		else
			if (j<l1.m.size())
			{
				t1 = l1.m[j];
				r += (t1);
			}
			else
			{
				t2 = l2.m[j];
				r += (t2);
			}
		temp.m.push_back((r % 10));
		r /= 10;
	}
	if (r != 0)
		temp.m.push_back((r % 10));
	return temp;
}

int difference(Longi &x, Longi &y, Longi &z, int length)
{
	for (int ix = 0; ix < (length); ix++) // проход по всем разрядам числа, начиная с последнего, не доходя до первого
	{
		if (ix < (length)) // если текущий разряд чисел не первый
		{
			x.m[ix + 1]--; // в следующуем разряде большего числа занимаем 1.
			z.m[ix] += 10 + x.m[ix]; // в ответ записываем сумму значения текущего разряда большего числа и 10-ти

		}
		else  // если текущий разряд чисел - первый
			z.m[ix] += x.m[ix]; // в ответ суммируем значение текущего разряда большего числа

		z.m[ix] -= y.m[ix]; // вычитаем значение текущего разряда меньшего числа

		if (z.m[ix] / 10 > 0) // если значение в текущем разряде двухразрядное
		{
			z.m[ix + 1]++; // переносим единицу в старший разряд
			z.m[ix] %= 10; // в текущем разряде отсекаем ее
		}
	}
	return 0;
}

Longi operator-(Longi l3, Longi l4) {

	Longi temp;
	int r = 0;
	int length;
	int n = max(l3.m.size(), l4.m.size());

	int k = 3; // если к == 3, значит числа одинаковой длинны
	length = l3.m.size();
	if (l3.m.size() > l4.m.size())
	{
		length = l3.m.size();
		k = 1; // если к == 1, значит первое число длиннее второго
	}
	else
		if (l4.m.size() > l3.m.size())
		{
			length = l4.m.size();
			k = 2; // если к == 2, значит второе число длиннее первого
		}
		else // если числа одинаковой длинны, то необходимо сравнить их веса
			for (int ix = 0; ix < length;) // поразрядное сравнение весов чисел
			{
				if (l3.m[ix] > l4.m[ix]) // если разряд первого числа больше
				{
					k = 1; // значит первое число длиннее второго
					break; // выход из цикла for
				}

				if (l4.m[ix] > l3.m[ix]) // если разряд второго числа больше
				{
					k = 2; // значит второе число длиннее первого
					break; // выход из цикла for
				}
				if (l4.m[ix] == l3.m[ix]) {
					k = 1;
					break;
				}

			} // конец for
	for (int i = 0; i<length; i++) {
		temp.m.push_back(0);
	}
	if (k == 1) difference(l3, l4, temp, length);// - если первое число больше второго,
	if (k == 2) difference(l4, l3, temp, length); //- если второе число больше первого.
	while (temp.m.size() > 1 && temp.m.back() == 0)
		temp.m.pop_back();

	return temp;
}

Longi operator*(Longi a, int b) {
	Longi c;
	int size_a = a.m.size();
	int size_b = 5;
	int length = size_a + size_b + 1;
	for (int i = 0; i<length; i++) {
		c.m.push_back(0);
	}
	for (int ix = 0; ix < size_a; ix++)
		c.m[ix] += a.m[ix] * b;

	for (int ix = 0; ix < length; ix++)
	{
		c.m[ix + 1] += c.m[ix] / 10;
		c.m[ix] %= 10;
	}

	while (c.m.size() > 1 && c.m.back() == 0)
		c.m.pop_back();

	return c;

}

Longi operator*(Longi b, Longi a) {
	Longi c;
	int size_a = a.m.size();
	int size_b = b.m.size();
	int length = size_a + size_b + 1;
	for (int i = 0; i<length; i++) {
		c.m.push_back(0);
	}
	for (int ix = 0; ix < size_a; ix++)
		for (int jx = 0; jx < size_b; jx++)
			c.m[ix + jx] += a.m[ix] * b.m[jx];

	for (int ix = 0; ix < length; ix++)
	{
		c.m[ix + 1] += c.m[ix] / 10;
		c.m[ix] %= 10;
	}

	while (c.m.size() > 1 && c.m.back() == 0)
		c.m.pop_back();


	return c;
}



Longi operator/(Longi a, int b) {
	int carry = 0;
	Longi c;
	for (int i = 0; i<a.m.size(); i++) {
		c.m.push_back(0);
	}

	int base = 1000;
	for (int i = a.m.size(); i >= 0; --i) {
		int cur = a.m[i] + carry*base;
		c.m[i] = int(cur / b);
		carry = int(cur % b);
	}

	while (c.m.size() > 1 && c.m.back() == 0)
		c.m.pop_back();
	return c;
}

void Longi::_shift_right() {
	if (this->m.size() == 0) {
		this->m.push_back(0);
		return;
	}
	this->m.push_back(this->m[this->m.size() - 1]);
	// здесь размер массива равен как минимум двум и перебор идет до предпоследнего разряда,
	// поэтому i имеет "верный" тип size_t
	for (size_t i = this->m.size() - 2; i > 0; --i) this->m[i] = this->m[i - 1];
	this->m[0] = 0;
}

Longi operator /(Longi left, Longi right) {
	int x = 0;
	Longi l0, t, result, current, temp;
	l0.m.push_back(0);
	while (left.m.size() != 0) {
		if (left.m.back() == 0) {
			result.m.insert(result.m.begin(), 0);
			left.m.pop_back();
			continue;
		}
		while (current<right) {
			current.m.insert(current.m.begin(), left.m.back());
			left.m.pop_back();
		}
		Longi next;
		next = right*x;
		while (!(current<next)) {
			while (t.m.size() > 0)t.m.pop_back();
			x++;
			t = right*x;
			next.clear();
			next = right*(x + 1);
			while (t.m.size() > 1 && t.m.back() == 0)
				t.m.pop_back();
		};

		temp = current - t;
		if (!(temp.m[0] == 0 && temp.m.size() == 1)) {
			for (int i = 0; i < temp.m.size(); i++) {
				left.m.push_back(t.m[i]);
			}
		}
		current.clear();
		temp.clear();
		t.clear();
		result.m.insert(result.m.begin(), x);
		x = 0;
	}
	/*if (!(left==l0)){
	while (left <right ) {
	int count = 0;
	left.m.insert(left.m.begin(),0);
	result.m.insert(result.m.begin(),0);
	count++
	}
	}*/
	return result;
}
