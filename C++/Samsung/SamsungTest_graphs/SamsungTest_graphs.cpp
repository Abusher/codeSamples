// SamsungTest_graphs.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int mtx[2001][2001];
int n;
int d[2001];
int from[2001];
int to[2001];
int cost[2001];



void bfs(int x,int y)
{
	for (int i = 0; i <= n; i++) d[i] = 0;
	bool used[2001] = {0};
	int f[2001] = {0};
	f[0] = x;
	used[x] = true;
	int i = 0;
	int k = 1;
	while (f[i])
	{
		
		for (int j = 1; j <= mtx[f[i]][0]; j++)
		{
			int t = to[mtx[f[i]][j]];
			if ( t == f[i]) t = from[mtx[f[i]][j]];
			if (t && used[t] == false && t!=y)
			{
				d[t] = d[f[i]] + cost[mtx[f[i]][j]];
				f[k] = t;
				used[t] = true;
				 
				k++;
			}
		}
		i++;
	}

}
int diameter(int x, int y)
{
	int ww,v;
	ww = v = x;
	bfs(v,y);
	for (int i = 1; i <= n; i++)
	{
		if (d[v] < d[i]) {
			v = i;
		}
	}
	bfs(v,y);
	for (int i = 1; i <= n; i++)
	{
		if (d[ww] < d[i]) {
			ww = i;
		}
	}

	return d[ww];
}


int main()
{
	int t;
	scanf("%d", &t);
	int ans[2001] = {};
	
	for (int j = 1; j <= t; j++)
	{
		
		scanf("%d", &n);
		
		
		
		for (int i = 1; i <= n - 1; i++)
		{
			int l, r, w;
			scanf("%d %d %d", &w, &l, &r);
			from[i] = l;
			to[i] = r;
			cost[i] = w;
			mtx[l][mtx[l][0] + 1] = i;
			mtx[r][mtx[r][0] + 1] = i;
			mtx[l][0]++;
			mtx[r][0]++;
			
		}
		

		for (int i = 1; i <= n - 1; i++)
		{
			
			int cost1 = diameter(from[i],to[i]);
 			int cost2 = diameter(to[i], from[i]);
			//printf("%d %d \n", cost1, cost2);
			if (ans[j] < (cost1 + cost2 + cost[i])) {
				ans[j] = cost1 + cost2 + cost[i];
			}
		}
		//std::cout << ans[t];
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= mtx[i][0]; k++) mtx[i][k] = 0;
			mtx[i][0] = 0;
		}
			
		
	}

	for (int i = 1; i <= t; i++)
	{
		printf("%d %d \n", i, ans[i]);
	}
    return 0;
}

