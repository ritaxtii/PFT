#include <iostream>
#include <vector>

using namespace std;

int arr[9][9] = {},sum=64;
vector<pair<int, int>> vec;
//^
void a1(int x, int y)
{
    for (int i = x; i > 0; i--)
    {
        if (arr[i][y] == 0) sum--,arr[i][y]=1;
    }
}
//<^
void a2(int x, int y)
{
    for (int i = x, j = y; i > 0 && j > 0; i--, j--)
    {
        if(arr[i][j]==0) sum--, arr[i][j] = 1;
    }
}
//^>
void a3(int x, int y)
{
    for (int i = x, j = y; i > 0 && j <=8 ; i--, j++)
    {
        if (arr[i][j] == 0) sum--, arr[i][j] = 1;
    }
}
//v
void a4(int x, int y)
{
    for (int i = x; i <=8;i++)
    {
        if (arr[i][y] == 0) sum--, arr[i][y] = 1;
    }
}
//<v
void a5(int x, int y)
{
    for (int i = x, j = y; i <=8 && j > 0; i++, j--)
    {
        if (arr[i][j] == 0) sum--, arr[i][j] = 1;
    }
}
//v>
void a6(int x, int y)
{
    for (int i = x, j = y; i <=8 && j <=8; i++, j++)
    {
        if (arr[i][j] == 0) sum--, arr[i][j] = 1;
    }
}
//<
void a7(int x, int y)
{
    for (int i = y; i > 0; i--)
    {
        if (arr[x][i] == 0) sum--, arr[x][i] = 1;
    }
}
//>
void a8(int x, int y)
{
    for (int i = y; i <=8; i++)
    {
        if (arr[x][i] == 0) sum--, arr[x][i] = 1;
    }
}
void ck()
{
    for (int i = 0; i < vec.size(); i++)
    {
        int x = vec[i].first, y = vec[i].second;
        a1(x, y);
        a2(x, y);
        a3(x, y);
        a4(x, y);
        a5(x, y);
        a6(x, y);
        a7(x, y);
        a8(x, y);
        
    }
}
int main()
{
    int n,x,y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;
        vec.push_back(make_pair(y, x));

    }
    ck();
    cout << sum<<endl;
   /* for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <=8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
