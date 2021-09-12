#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(0);
	long long int n,q,p,k=0;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back(p+vec[i]);
	}
	
	for (int i = vec.size() - 2; i >= 0; i--)
	{
		vec[i] = min(vec[i + 1], vec[i]);
	}

	vec.erase(vec.begin());
	long long int Q;
	for (int i = 0; i < q; i++)
	{
		cin >> Q;
		long long w = upper_bound(vec.begin(), vec.end(), Q) - vec.begin() ;
		if (w > 0) cout << w;
		else { cout << 0; }
		cout << endl;
	}

	
	


}