#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<int,int>> vec;
	vec.push_back(make_pair(0,0));
	long long int n, q, p, k = 0;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back(make_pair(p + vec[vec.size()-1].first,i+1));
		int r = vec.size()-2;
		while (r >= 0)
		{
			if (vec[r + 1].first <= vec[r].first)
			{
				vec.erase(vec.begin() + r);
				r--;
			}
			else break;
		}
	}
	
	long long int Q;
	for (int i = 0; i < q; i++)
	{
		cin >> Q;

		long long int low = 0, high = vec.size()-1,last=0;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (vec[mid].first > Q)
			{
				high = mid - 1;
			}
			else if (vec[mid].first == Q)
			{
				last = mid;
				break;
			}
			else
			{
				last = mid;
				low = mid + 1;
			}
		}
		
			cout << vec[last].second << endl;
		
		
	}

}