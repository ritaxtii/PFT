#include <bits/stdc++.h>

using namespace std;

string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
vector<int> vec;
int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		int k = s[i],sum=0;
		if (vec.size() == 0)
		{
			vec.push_back(k % 2);
			//cout << k % 2;
			k /= 2;
			vec.push_back(k % 2);
			//cout << k % 2;
			k /= 2;
			
			for (int j = 0; j < 6; j++)
			{
				sum += (k % 2) * (pow(2, j));
				//cout << k % 2;
				k /= 2;
			}
		}
		else if (vec.size() == 2)
		{
			//cout << vec[1] << vec[0];
			sum += vec[1] * pow(2, 5);
			
			sum += vec[0] * pow(2, 4); //cout << sum<<" ";
			vec.clear();
			for (int j = 0; j < 4; j++)
			{
				vec.push_back(k % 2);
				k /= 2;
			}
			for (int j = 0; j < 4; j++)
			{
				sum += (k % 2) * (pow(2, j));
				//cout << k % 2;
				k /= 2;
			}

			
		}
		else if (vec.size() == 4)
		{	sum += vec[0] * pow(2, 2);
			sum += vec[1] * pow(2, 3);
			sum += vec[2] * pow(2, 4);
			sum += vec[3] * pow(2, 5);

			
			vec.clear();
			for (int j = 0; j < 6; j++)
			{
				vec.push_back(k % 2);
				k /= 2;
			}
			for (int j = 0; j < 2; j++)
			{
				sum += (k % 2) * (pow(2, j));
				//cout << k % 2;
				k /= 2;
			}
			cout << b64[sum];
			sum = 0;
			sum += vec[0] * pow(2, 0);
			sum += vec[1] * pow(2, 1);
			sum += vec[2] * pow(2, 2);
			sum += vec[3] * pow(2, 3);
			sum += vec[4] * pow(2, 4);
			sum += vec[5] * pow(2, 5);


			vec.clear();
			
		}
		//cout << " " << sum << " ";
		cout << b64[sum]; 
	
		

	}
	if (vec.size() == 4)
	{
		int sum = 0;

		sum += vec[0] * pow(2, 2);
		sum += vec[1] * pow(2, 3);
		sum += vec[2] * pow(2, 4);
		sum += vec[3] * pow(2, 5);
		cout << b64[sum];
		cout << "=";
	}
	else if (vec.size() == 2)
	{
		int sum = 0;

		sum += vec[0] * pow(2, 4);
		sum += vec[1] * pow(2, 5);
		
		cout << b64[sum];
		cout << "==";
	}

	
}