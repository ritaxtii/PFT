#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec;
	int numofequal = 0;
	string s;
	getline(cin, s);
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '=');
		else
		{
		int k;
		if (s[i] >= 'A' && s[i] <= 'Z') k = s[i] - 'A';
		else if (s[i] >= 'a' && s[i] <= 'z') k = s[i] - 'a' + 26;
		else if (s[i] >= '0' && s[i] <= '9') k = s[i] - '0' + 52;
		else if (s[i] == '+') k = 62;
		else if (s[i] == '/') k = 63;
		
			int j = 0;
			while (j < numofequal*2)
			{
				k /= 2;
				j++;
			}
		
			j = 0;
			while (j < 6 - (numofequal * 2))
			{
				vec.push_back(k % 2);
				k /= 2;
				j++;
			}
			numofequal = 0;
		}

	}
	for (int i = vec.size()-8; i >=0; i-=8)
	{
		int sum = 0;
		for (int j = 0; j < 8; j++)
		{
			sum += vec[i + j] * pow(2, j);
		}
		cout << char(sum);
	}
	
}