#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec[4];
	int x;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> x;
			vec[i].push_back(x);
		}
	}
	cin.ignore();
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i += 2)
	{
		if (s[i] == 'L')
		{
			for (int j = 0; j < 4; j++)
			{
				int k = 0;
				while (k < vec[j].size() - 1)
				{
					if (vec[j][k] == 0) vec[j].erase(vec[j].begin() + k);
					else if (vec[j][k] == vec[j][k + 1])
					{
						vec[j][k] *= 2;
						vec[j].erase(vec[j].begin() + k + 1);
					}
					else k++;
				}
				while (vec[j].size() != 4)
				{
					vec[j].push_back(0);
				}
			}
		}
		if (s[i] == 'R')
		{
			for (int j = 0; j < 4; j++)
			{
				
				while (!vec[j].empty())
				{
					if (vec[j][vec[j].size() - 1] == 0)
						vec[j].pop_back();
					else break;
				}
				int k = vec[j].size() - 1;
				while (k > 0)
				{
					if (vec[j][k] == vec[j][k - 1])
					{
						vec[j][k] *= 2;
						vec[j].erase(vec[j].begin() + k - 1);
					}
					k--;
				}
				while (vec[j].size() != 4)
				{
					vec[j].insert(vec[j].begin(), 0);
				}

				
			}
		}
		if (s[i] == 'D')
		{
			for (int j = 0; j < 4; j++)
			{
				int error = 0;
				do
				{
					error = 0;
					for (int k = 3; k > 0; k--)
					{
						if (vec[k][j]!=0 && vec[k][j] == vec[k - 1][j])
						{
							vec[k][j] *= 2;
							vec[k - 1][j] = 0;
							error++;
						}
					}
					for (int k = 3; k > 0; k--)
					{
						if (vec[k][j] == 0)
						{
							for (int l = k - 1; l >= 0; l--)
							{
								if (vec[l][j] != 0)
								{
									error++;
									vec[k][j] = vec[l][j];
									vec[l][j] = 0;
									break;
								}
							}
						}
					}
					
				} while (error != 0);
				
			}
		}
		if (s[i] == 'U')
		{
			for (int j = 0; j < 4; j++)
			{
				int error = 0;
				do
				{
					error = 0;
					for (int k = 0; k < 3; k++)
					{
						if (vec[k][j] != 0 && vec[k][j] == vec[k + 1][j])
						{
							vec[k][j] *= 2;
							vec[k + 1][j] = 0;
							error++;
						}
					}
					for (int k = 0; k < 3; k++)
					{
						if (vec[k][j] == 0)
						{
							for (int l = k + 1; l < 4; l++)
							{
								if (vec[l][j] != 0)
								{
									error++;
									vec[k][j] = vec[l][j];
									vec[l][j] = 0;
									break;
								}
							}
						}
					}

				} while (error != 0);

			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}