#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	vector<pair<string, string>> Arr;
	Arr.push_back(make_pair("Kob", ""));
	Arr.push_back(make_pair("Romtham", ""));
	Arr.push_back(make_pair("Jojo", ""));
	getline(cin, s);
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ',')
		{
			Arr[k].second += s[i];
		}
		else
			k++;
	}
	int Ans = -1;
	for (int i = 0; i < 3; i++)
	{
		bool az = false, num = false, AZ = false, sp = false;
		for (int j = 0; j < Arr[i].second.size(); j++)
		{
			if (Arr[i].second[j] >= 'a' && Arr[i].second[j] <= 'z')
				az = true;
			else if (Arr[i].second[j] >= '0' && Arr[i].second[j] <= '9')
				num = true;
			else if (Arr[i].second[j] >= 'A' && Arr[i].second[j] <= 'Z')
				AZ = true;
			else if (Arr[i].second[j] == '$' || Arr[i].second[j] == '#' || Arr[i].second[j] == '@')
				sp = true;
		}
		if (az && AZ && num && sp)
		{
			Ans = i;
			break;
		}
	}
	cout << Arr[Ans].second << " (" << Arr[Ans].first << ")";
	
}