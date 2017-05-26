// Samsung_squares_dp.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


using namespace std;
int main()
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	int cols[101] = {};
	int res[1 << 10][101] = {};
	for (int i = 0; i < N; i++)
	{
		char str[101];
		scanf("%s", &str);
		for (int j = 0; j < M; j++)
		{
			if (str[j] == '#') {
				cols[j] |= (1 << i);
			}
		}
	}
	int ans = 0;
	for (int j = 1; j < M; j++)
	{
		for (int config = 0; config < (1 << N); config++)
		{
			for (int prevconfig = 0; prevconfig < (1 << N); prevconfig++)
			{
				if ((config&cols[j]) == cols[j] && (prevconfig&cols[j - 1]) == cols[j - 1])
				{
					int cur = config;
					int numBit = 0;
					int prevBitIs0 = 0;
					int curans = 0;

					while (numBit < N)
					{
						int bit = cur&(1 << numBit);
						if (bit == 0)
						{
							if (prevBitIs0)
							{
								prevBitIs0 = 0;
								if (((~prevconfig)&(1 << numBit)) && (~prevconfig)&(1 << (numBit - 1)))
								{
									cur |= (1 << numBit);
									cur |= (1 << (numBit - 1));
									curans++;
								}
							}
							else {
								prevBitIs0 = 1;
							}

						}
						else {
							prevBitIs0 = 0;
						}
						numBit++;
						if (res[cur][j] < res[prevconfig][j - 1] + curans) res[cur][j] = res[prevconfig][j - 1] + curans;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < (1 << N); i++)
	{
		if (res[i][M - 1] > ans) ans = res[i][M - 1];
	}

	printf("%d", ans);
    return 0;
}

