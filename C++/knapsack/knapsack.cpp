#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int a[301][11000] = {};


int optimal_weight(int W, const vector<int> &v) {
	//write your code here
	int current_weight = a[0][0];

	for (int n = 1; n <= v.size(); n++)
	{
		int weight = v[n - 1];

		for (int w = 1; w <= W; w++)
		{

			a[n][w] = a[n - 1][w];
			if (weight <= w)
				a[n][w] = max(a[n][w], a[n - 1][w - weight] + weight);
		}
	}

	return a[v.size()][W];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);

	for (int i = 0; i < n; i++) {
		std::cin >> w[i];

	}
	/*for (int i = 0; i <= n; i++)
	{
	a[i][0] = 0;
	}
	for (int i = 0; i <= W; i++)
	{
	a[0][i] = 0;
	}*/
	std::cout << optimal_weight(W, w) << '\n';

	return 0;
}

