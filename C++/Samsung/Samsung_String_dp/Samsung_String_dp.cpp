// Samsung_String_dp.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

const int Nmax = 1e9;

int mtx[3][1001];

//int st[1001];
//int mask[1001];

int main()
{
	int N, C, K;
	scanf("%d %d %d", &N, &C, &K);
	
	char str[1001];
	scanf("%s", &str);

	
	for (int i = 1; i <= N; i++)
	{
		mtx[0][i] = mtx[0][i - 1];
		mtx[1][i] = mtx[1][i - 1];
		mtx[2][i] = mtx[2][i - 1];
		if (str[i-1] == 'S') mtx[0][i]+=1;
		if (str[i-1] == 'N') mtx[1][i]+=1;
		if (str[i-1] == 'M') mtx[2][i]+=1;

	}
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= N; j++) cout << mtx[i][j];
		cout << endl;
	}*/
	
	int ans = C + K*N;
	for (int l = 2; l <= N; l++)
	{
		int st[1001] = {};
		int mask[1001] = {};
		
		for (int i = 1; i < l; i++)
		{
			st[i] = Nmax;
			mask[i] = 0;
		}
		
		//cout <<"l = "<< l << endl;
		for (int i = l; i <= N; i++)
		{
			int steps = Nmax;
			int msk = 0;
			int M = 0;
			int changed = 0;
			if (mtx[0][i] != mtx[0][i - l]) changed += 1;
			if (mtx[1][i] != mtx[1][i - l]) changed+=(1<<1);
			if (mtx[2][i] != mtx[2][i - l]) changed+=(1<<2);

			if (changed == 0) M = 1 + (1 << 1) + (1 << 2);
			else if (changed ==1
				|| changed ==(1<<1)
				|| changed ==(1<<2)) M = changed;
			//cout << "M = " << M;
			if (M != 0) {
				if (st[i - l] != Nmax)
				{
					steps = st[i - l] + 1;
					msk = M;
				}
			}
				for (int j = i - l + 1; j < i; j++)
				{
					int k = M&mask[j];
					

					
					if ((M&mask[j])!=0 && (st[j] + 1 < steps))
					{
						steps = st[j] + 1;
						msk = M&mask[j];
						
					}
				}
		
			st[i] = steps;
			mask[i] = msk;
		}
		//cout << endl;
		if (st[N] == Nmax)
		{
			
			cout << ans<<endl;
			return 0;
		}
		else {
			int tmp = C*l + K*st[N];
			if (tmp < ans) ans = tmp;
			
		}
	}
	cout << ans;
    return 0;
}

