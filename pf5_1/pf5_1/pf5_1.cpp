#include <bits/stdc++.h>
using namespace std;
int n,mn=100000;
int mem[1000][1000] = {};
void tv(int x , int y, int sum)
{
    int now = mem[x][y];
    mem[x][y] = 0;
    bool b = true;
    if (mem[x - 1][y - 1] != 0) tv(x - 1, y - 1, sum + mem[x - 1][y - 1]), b = false;
    if (mem[x - 1][y] != 0) tv(x - 1, y, sum + mem[x - 1][y]), b = false;
    if (mem[x - 1][y + 1] != 0) tv(x - 1, y + 1, sum + mem[x - 1][y + 1]), b = false;
    if (mem[x][y - 1] != 0) tv(x, y - 1, sum + mem[x][y - 1]), b = false;
    if (mem[x][y + 1] != 0) tv(x, y + 1, sum + mem[x][y + 1]), b = false;
    if (mem[x + 1][y - 1] != 0) tv(x + 1, y - 1, sum + mem[x + 1][y - 1]), b = false;
    if (mem[x + 1][y + 1] != 0) tv(x + 1, y + 1, sum + mem[x + 1][y + 1]), b = false;
    if (mem[x + 1][y] != 0) tv(x + 1, y, sum + mem[x + 1][y]), b = false;

    if (sum < mn) mn = sum;
    
    mem[x][y] = now;
}
int main()
{
    cin >> n;
    string c;
    int a, b;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            cin >> c;
            if (c[0] == 'S') a = i, b = j;
            else
            mem[i][j] = stoi(c);
            
        }
    }
    tv(a,b,0);
    cout << mn;

}
