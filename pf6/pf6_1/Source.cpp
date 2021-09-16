#include <bits/stdc++.h>
using namespace std;

int n, m,k=0;
char island[3000][3000];
void light(int i, int j)
{
	island[i][j] = '0';
	if (i!=0)
	{
		if (j!=0)
		{
			if (island[i - 1][j - 1] == '1') light(i - 1, j - 1);
		}
		if (j!=m-1)
		{
			if (island[i - 1][j + 1] == '1') light(i - 1, j + 1);
		}
		if (island[i - 1][j] == '1') light(i - 1, j);
		
	}
	if (i!=n-1)
	{
		if (j!=0)
		{
			if (island[i + 1][j - 1] == '1') light(i + 1, j - 1);
		}
		if (j!=m-1)
		{
			if (island[i + 1][j + 1] == '1') light(i + 1, j + 1);
		}
		if (island[i + 1][j] == '1') light(i + 1, j);
	}
	if (j!=0)
	{
		if (island[i][j - 1] == '1') light(i, j - 1);
	}
	if (j!=m-1)
	{
		if (island[i][j + 1] == '1') light(i, j + 1);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> island[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (island[i][j] == '1')
			{
				light(i, j);
				k++;
			}
		}
	}
	cout << k;
	
}