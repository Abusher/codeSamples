// Iron_Sticks_dp.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>	

using namespace std;

int a[51];

int dp[51][1000];

int main()
{
	int n;
	cin >> n;
	
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++) dp[i][j] = -1;
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (dp[i][j] != -1)
			{
				if (dp[i + 1][j] < dp[i][j]) dp[i + 1][j] = dp[i][j];
				if (dp[i + 1][j + a[i + 1]] < dp[i][j] + a[i + 1]) dp[i + 1][j + a[i + 1]] = dp[i][j] + a[i + 1];

				int y = j - a[i + 1];
				int k = 0;
				if (y < 0) {
					y *= -1;
					k = a[i + 1] - j;
				}
				if (dp[i + 1][y] < dp[i][j] + k)
				{
					 dp[i + 1][y] = dp[i][j] + k;
					
				}
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++) cout << dp[i][j]<<" ";
		cout << endl;
	}
	cout << dp[n][0];
    return 0;
}

