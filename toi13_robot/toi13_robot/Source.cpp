#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n, m, mn;
int arr[2001][2001];
int dp[2001][2001] = {};
int total = 0,all=0;
vector<pair<int, int>> vec;
void keep(int i, int j,int sum)
{
	if (arr[i][j] == 'X')
	{
		mn = sum;
	}
	dp[i][j] = 1;
	if (sum < mn - 1)
	{
		if (i != 0)
		{
			if(dp[i-1][j]==0&&arr[i-1][j]!='W')
				keep(i - 1, j, sum + 1);
		}
		if (i != n - 1) 
		{
			if (dp[i + 1][j] == 0 && arr[i + 1][j] != 'W')
				keep(i + 1, j, sum + 1);
		}
		if (j != 0)
		{
			if (dp[i][j-1] == 0 && arr[i][j-1] != 'W')
				keep(i, j - 1, sum + 1);	
		}
			
		if (j != m - 1)
		{
			if (dp[i][j + 1] == 0 && arr[i][j + 1] != 'W')
				keep(i, j + 1, sum + 1);
		}
	}
	dp[i][j] = 0;
}
int main()
{
	cin >> n >> m;
	char xx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> xx;
			arr[i][j] = xx;
			if (xx == 'A')
				vec.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		mn = INT_MAX;
		keep(vec[i].x, vec[i].y,0);
		if (mn != INT_MAX) total += (mn * 2), all++;
	}
	cout << all << " " << total;
}