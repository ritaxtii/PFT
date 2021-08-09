

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> vec;
bool ck(int x, int y)
{
    bool b = true;
    // -----------
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].first == x)
        {
            b = false;
            break;
        }
    }
    //   |
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second == y)
        {
            b = false;
            break;
        }
    }
    // <^ v>
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second - y == vec[i].first - x)
        {
            b = false;
            break;
        }
    }
    // <v ^>
    for (int i = 0; i < vec.size(); i++)
    {
        if (abs(vec[i].second - y) == abs(vec[i].first - x))
        {
            b = false;
            break;
        }
    }
    
    return b;
}
int main()
{
    int n,sum=0;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (ck(i, j)) sum++;
            
        }
     
    }
    cout << sum;

}
