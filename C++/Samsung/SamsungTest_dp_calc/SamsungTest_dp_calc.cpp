// SamsungTest_dp_calc.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <stdio.h>



using namespace std;

int calc(int x, int y, int op)
{
	if (op == 1) return x + y;
	if (op == 2) return x - y;
	if (op == 3) return x*y;
	if (op == 4) return x / y;
	
}
int main()
{
	int N, O, M;
	int maxA = 0;
	cin >> N >> O >> M;
	int number[10] = {};
	int operations[4] = {};

	bool available[1000] = {};
	int numbers[1000] = {};

	int dp[9][1000] = {};
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		number[k] = 1;
		if (k > maxA) maxA = k;
	}
	for (int i = 0; i < O; i++)
	{
		int k;
		cin >> k;
		operations[i] = k;
	}
	int W;
	cin >> W;
	for (int i = 0; i < 10; i++)
	{
		if (number[i])
		{
			for (int j = 0; j < 10; j++)
			{
				if (number[j])
				{
					for (int k = 0; k < 10; k++)
					{
						if (number[k])
						{
							int t = i * 100 + j * 10 + k;
							numbers[t] = 3;
							available[t] = true;
						}
					}
					int t = i * 10 + j;
					numbers[t] = 2;
					available[t] = true;
				}
			}
			numbers[i] = 1;
			available[i] = true;
		}
	}
	if (numbers[W])
	{
		cout << numbers[W];
		return 0;
	}
	maxA = maxA * 100 + maxA * 10 + maxA;
	for (int i = 1; i <= maxA; i++)
	{
		if (numbers[i]==0) continue;
		for (int j = 1; j <= maxA; j++)
		{
			if (numbers[j] == 0) continue;
			for (int op = 0; op < O; op++)
			{
				
				int t = calc(i, j, operations[op]);
				if (t >= 0 && t <= 999)
				{
					if(dp[0][t]==0 || dp[0][t]>(numbers[i] + numbers[j] + 1)) dp[0][t] = numbers[i] + numbers[j] + 1;

				}

			}
		}
	}
	/*if (dp[0][W] != 0)
	{
		cout << dp[0][W]+1;
		return 0;
	}*/
	int m = (M - 1) / 2;
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < 1000; j++)
		{
			if (dp[i - 1][j] != 0)
			{
				for (int numb = 1; numb < 1000; numb++)
				{
					if (available[numb])
					{
						for (int op = 0; op < O; op++)
						{
							int t = calc(j, numb, operations[op]);
							if(t>=0 && t<=999)
							{
								if (dp[i][t] == 0 || dp[i][t]>(dp[i-1][j] + numbers[numb] + 1)) dp[i][t] = dp[i - 1][j] + numbers[numb] + 1;
								
							}
						}
					}
				}
			}
		}
	}
	int ans = 21;
	for (int i = 0; i < m; i++)
	{
		if (dp[i][W] != 0 && dp[i][W] + 1 < ans) {
			ans = dp[i][W] + 1;
		}
	}
	if (ans <= M) cout << ans;
	else cout << -1;
    return 0;
}

