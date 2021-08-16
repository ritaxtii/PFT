#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
vector<int> vec;

int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		int k = s[i],j=0;
		stack<int> v;
		while (j<8)
		{

			v.push(k % 2);


			k /= 2;
			j++;
		}

		while (!v.empty())
		{
			vec.push_back(v.top());
			v.pop();
		}
	}
	for (int i = 0; i < vec.size(); i += 6)
	{
		int sum = 0,k = 5;
		for (int j = i; j < i + 6 && j < vec.size(); j++)
		{
			sum += pow(2, k) * vec[j];
			k--;
		}

		if (sum < 26) cout << char('A' + sum);
		else if (sum < 52) cout << char('a' + sum - 26);
		else if (sum < 62) cout << sum - 52;
		else if (sum == 62) cout << "+";
		else cout << "/";
	}
	if (s.size() % 3 == 1) cout << "==";
	else if (s.size() % 3 == 2) cout << "=";
}
