// SamsungTest_scheme_dp.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <stdio.h>

using namespace std;



bool overlaps[301][301];
bool used[301];
int num_used = 0;
const int M = 300;
int order[301];

bool overlaps_any(int A)
{
	for (int i = 1; i <= M; i++)
	{
		if (used[i] && overlaps[i][A])
			return true;
	}
	return false;
}
int find_next()
{
	for (int i = 1; i <= M; i++)
	{
		if (used[i] && !overlaps_any(i))
		{
			used[i] = false;
			return i;
		}
	}
	return -1;
}
bool find_order()
{
	for (int step = 1; step <= num_used; step++)
	{
		int s = find_next();
		if (s < 0)
			return false;
		order[s] = step;
	}
	return true;
}
int main()
{
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++)
	{
		int s[500][500] = {};
		int Xmax[301] = {};
		int Xmin[301] = {};
		int Ymax[301] = {};
		int Ymin[301] = {};
		
		
		int n,k;
		cin >> n>>k;
		for (int i = 0; i < 301; i++)
		{
			Xmax[i] = -1;
			Ymax[i] = -1;
			Xmin[i] = 501;
			Ymin[i] = 501;
		}
		
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				int color;
				cin >> color;
				s[x][y] = color;
				if (color != 0)
				{
					
					if (!used[color]) {
						used[color] = true;
						num_used++;
					}
					if (Xmax[color] < y) Xmax[color] = y;
					if (Ymax[color] < x) Ymax[color] = x;
					if (Xmin[color] > y) Xmin[color] = y;
					if (Ymin[color] > x) Ymin[color] = x;
				}

			}
		}
		for (int color = 1; color <=M; color++)
		{
			if (used[color])
			{
				for (int y = Ymin[color]; y <= Ymax[color]; y++)
				{
					for (int x = Xmin[color]; x <= Xmax[color]; x++)
					{
						if (s[y][x] != color) overlaps[color][s[y][x]] = true;
					}
				}
			}
		}
		if (find_order())
		{
			cout << '#' << test << " " << order[k] << endl;
		}
		else {
			cout << '#' << test << " " << -1<<endl;
		}

		for (int i = 0; i <= M; i++)
		{
			for (int j = 0; j <= M; j++) overlaps[i][j] = false;
			used[i] = false;
			order[i] = 0;
		}
		num_used = 0;
	}
	
    return 0;
}

