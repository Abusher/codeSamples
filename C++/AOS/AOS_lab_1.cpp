// AOS_lab_1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <time.h>
#include <math.h>;

using namespace std;

template <typename S>
long long summ(S a)
	{
	    S a1 = 1, a2 = 2, a3 = 1, a4 = 2, a5 = 1, a6 = 2, a7 = 1, a8 = 2, a9 = 1;
		int t1 = clock();
		for (int i = 0; i < 10000000; i++)
		{
			
		}
		int t2 = clock();
		
		int t3 = clock();
		for (int i = 0; i < 10000000; i++)
		{
			a += a1;
			a1 += a2;
			a2 += a3;
			a3 += a4;
			a4 += a5;
			a5 += a6;
			a6 += a7;
			a7 += a8;
			a8 += a9;
			a += a9;
			a += a1;
			a1 += a2;
			a2 += a3;
			a3 += a4;
			a4 += a5;
			a5 += a6;
			a6 += a7;
			a7 += a8;
			a8 += a9;
			a += a9;
		}
		int t4 = clock();
		
		
		long long k = 20 * 10000000 / (t4- t3 - t2 + t1);
		return k*1000;
	}
template <typename D>
long long divide(D a)
{
	D a1 = 1, a2 = 2, a3 = 1, a4 = 2, a5 = 1, a6 = 2, a7 = 1, a8 = 2, a9 = 1;
	int t1 = clock();
	for (int i = 0; i < 10000000; i++)
	{

	}
	int t2 = clock();

	int t3 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		a /= a1;
		a /= a2;
		a /= a3;
		a /= a4;
		a /= a5;
		a /= a6;
		a /= a7;
		a /= a8;
		a /= a9;
		a /= a9;
		a /= a1;
		a /= a2;
		a /= a3;
		a /= a4;
		a /= a5;
		a /= a6;
		a /= a7;
		a /= a8;
		a /= a9;
		a /= a9;
	}
	int t4 = clock();

	
	long long k = 20 * 10000000 / (t4 - t3 - t2 + t1);
	return k * 1000;
}
template <typename Sub>
long long Substraction(Sub a)
{
	Sub a1 = 1, a2 = 2, a3 = 1, a4 = 2, a5 = 1, a6 = 2, a7 = 1, a8 = 2, a9 = 1;
	int t1 = clock();
	for (int i = 0; i < 10000000; i++)
	{

	}
	int t2 = clock();

	int t3 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		a -= a1;
		a1 -= a2;
		a2 -= a3;
		a3 -= a4;
		a4 -= a5;
		a5 -= a6;
		a6 -= a7;
		a7 -= a8;
		a8 -= a9;
		a -= a9;
		a -= a1;
		a1 -= a2;
		a2 -= a3;
		a3 -= a4;
		a4 -= a5;
		a5 -= a6;
		a6 -= a7;
		a7 -= a8;
		a8 -= a9;
		a -= a9;
	}
	int t4 = clock();

	
	long long k = 20 * 10000000 / (t4 - t3 - t2 + t1);
	return k * 1000;
}
template <typename M>
long long multiply(M a)
{
	M a1 = 1, a2 = 2, a3 = 1, a4 = 2, a5 = 1, a6 = 2, a7 = 1, a8 = 2, a9 = 1;
	int t1 = clock();
	for (int i = 0; i < 10000000; i++)
	{

	}
	int t2 = clock();

	int t3 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		a *= a1;
		a1 *= a2;
		a2 *= a3;
		a3 *= a4;
		a4 *= a5;
		a5 *= a6;
		a6 *= a7;
		a7 *= a8;
		a8 *= a9;
		a *= a9;
		a *= a1;
		a1 *= a2;
		a2 *= a3;
		a3 *= a4;
		a4 *= a5;
		a5 *= a6;
		a6 *= a7;
		a7 *= a8;
		a8 *= a9;
		a *= a9;
	}
	int t4 = clock();

	
	long long k = 20 * 10000000 / (t4 - t3 - t2 + t1);
	return k * 1000;
}

int main()
{
	double res[5][4] = {};

	{
		int a = 1000;
		res[0][0] = summ(a);
		res[0][1] = Substraction(a);
		res[0][3] = divide(a);
		res[0][2] = multiply(a);
	}
	
	{
		double b = 1000;
		res[1][0] = summ(b);
		res[1][1] = Substraction(b);
		res[1][3] = divide(b);
		res[1][2] = multiply(b);
	}
	
	{
		float l = 1000;
		res[2][0] = summ(l);
		res[2][1] = Substraction(l);
		res[2][3] = divide(l);
		res[2][2] = multiply(l);
	}

	{
		long long c = 1000;
		res[3][0] = summ(c);
		res[3][1] = Substraction(c);
		res[3][3] = divide(c);
		res[3][2] = multiply(c);
	}

	{

		char f = 1000;
		res[4][0] = summ(f);
		res[4][1] = Substraction(f);
		res[4][3] = divide(f);
		res[4][2] = multiply(f);
	}
	int k = 100;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			
			switch (j)
			{
			case 0: cout << "+  "; break;
			case 1: cout << "-  "; break;
			case 2: cout << "*  "; break;
			case 3: cout << "/  "; break;
			}
			switch (i)
			{
			case 0: cout << "int       "; break;
			case 1: cout << "double    "; break;
			case 2: cout << "float     "; break;
			case 3: cout << "long      "; break;
			case 4: cout << "char      "; break;
			}
			cout << scientific;
			cout << res[i][j];
			cout << "   ";
			
			int proc = 100 * res[i][j] / res[0][0];
			int x = 0;
			for (; x < (proc / 2); x++) cout << "X";
			for (int k = x+1; x < 60; x++) cout << " ";
			cout << proc << "%" << endl;
		}
	}
	system("pause");
	return 0;
}

