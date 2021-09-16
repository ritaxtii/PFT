#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0;
int arr[3000][3000] = {};
queue <pair<int, int>> que;
void run()
{
    while (!que.empty())
    {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        // arr[i][j]='0';
         //cout<<i<<" "<<j<<"\n";
        if (i - 1 >= 0)
        {
            if (arr[i - 1][j] == '1')
            {
                arr[i - 1][j] = '0';
                que.push(make_pair(i - 1, j));
            }
            if (j - 1 >= 0 && arr[i - 1][j - 1] == '1')
            {
                arr[i - 1][j - 1] = '0';
                que.push(make_pair(i - 1, j - 1));
            }
            if (j + 1 < m && arr[i - 1][j + 1] == '1')
            {
                arr[i - 1][j + 1] = '0';
                que.push(make_pair(i - 1, j + 1));
            }
        }
        if (i + 1 < n)
        {
            if (arr[i + 1][j] == '1')
            {
                arr[i + 1][j] = '0';
                que.push(make_pair(i + 1, j));
            }
            if (j - 1 >= 0 && arr[i + 1][j - 1] == '1')
            {
                arr[i + 1][j - 1] = '0';
                que.push(make_pair(i + 1, j - 1));
            }
            if (j + 1 < m && arr[i + 1][j + 1] == '1')
            {
                arr[i + 1][j + 1] = '0';
                que.push(make_pair(i + 1, j + 1));
            }
        }
        if (j - 1 >= 0 && arr[i][j - 1] == '1')
        {
            arr[i][j - 1] = '0';
            que.push(make_pair(i, j - 1));
        }
        if (j + 1 < m && arr[i][j + 1] == '1')
        {
            arr[i][j + 1] = '0';
            que.push(make_pair(i, j + 1));
        }
    }
    //cout<<".......\n";
    sum++;
}
int main()
{
    cin >> n >> m;
    char x[m + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = x[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                que.push(make_pair(i, j));
                run();
            }
        }
    }
    cout << sum;
    return 0;
}