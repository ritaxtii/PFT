

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	vector<int> vec;
	for (int i = 0; i < s.size(); i++)
	{
		int k;
		if (s[i] == '=') break;
		else if (s[i] >= 'A' && s[i] <= 'Z') k = s[i] - 'A';
		else if (s[i] >= 'a' && s[i] <= 'z') k = s[i] - 'a' + 26;
		else if (s[i] >= '0' && s[i] <= '9') k = s[i] - '0' + 52;
		else if (s[i] == '+') k = 62;
		else if (s[i] == '/') k = 63;

		stack<int> st;
		int j = 0;
		while (j < 6)
		{
			st.push(k % 2);
			k /= 2;
			j++;
		}
		while (!st.empty())
		{
			vec.push_back(st.top());
			st.pop();
		}
	}
	for (int i = 0; i < vec.size(); i+=8)
	{
		int sum = 0,k=7;
		for (int j = i; j < i + 8 && j < vec.size() ; j++)
		{
			sum += pow(2, k)*vec[j];
			k--;
		}
		
		cout << char(sum);
	}
}
