#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, z;
int arr[3000][3000], rb_x[1000], rb_y[1000], gi_x[1000], gi_y[1000], k = 0, m = 0;
int te[3000][3000] = {};
int kep[3000][3000];

queue <pair<pii, int>> que;

void run()
{

    while (!que.empty())
    {
        int i = que.front().first.first;
        int j = que.front().first.second;
        int sum = que.front().second;
        que.pop();
        if (i - 1 >= 0 && kep[i - 1][j] > sum + 1)
        {
            if (arr[i - 1][j] == 'E' || arr[i - 1][j] == 'A')
            {
                kep[i - 1][j] = sum + 1;
                que.push(make_pair(make_pair(i - 1, j), sum + 1));
            }

            //run(i-1,j,sum+1);
        }

        if (i + 1 < n && kep[i + 1][j] > sum + 1)
        {
            if (arr[i + 1][j] == 'E' || arr[i + 1][j] == 'A')
            {
                kep[i + 1][j] = sum + 1;
                que.push(make_pair(make_pair(i + 1, j), sum + 1));
            }

            //run(i+1,j,sum+1);
        }

        if (j - 1 >= 0 && kep[i][j - 1] > sum + 1)
        {
            if (arr[i][j - 1] == 'E' || arr[i][j - 1] == 'A')
            {
                kep[i][j - 1] = sum + 1;
                que.push(make_pair(make_pair(i, j - 1), sum + 1));
            }

            // run(i,j-1,sum+1);
        }

        if (j + 1 < z && kep[i][j + 1] > sum + 1)
        {
            if (arr[i][j + 1] == 'E' || arr[i][j + 1] == 'A')
            {
                kep[i][j + 1] = sum + 1;
                que.push(make_pair(make_pair(i, j + 1), sum + 1));
            }

            //run(i,j+1,sum+1);
        }

    }
}

int main()
{
    cin >> n >> z;
    char x[3000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < z; j++)
        {
            kep[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; j < z; j++)
        {
            arr[i][j] = x[j];
            if (arr[i][j] == 'X')
            {
                rb_x[k] = j;
                rb_y[k] = i;
                k++;
            }
            else if (arr[i][j] == 'A')
            {
                gi_x[m] = j;
                gi_y[m] = i;
                m++;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        kep[rb_y[i]][rb_x[i]] = 0;
        que.push(make_pair(make_pair(rb_y[i], rb_x[i]), 0));

    }
    run();
    int c = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        // cout<<gi_y[i]<<" "<<gi_x[i]<<"\n";
        if (kep[gi_y[i]][gi_x[i]] != INT_MAX)

        {
            sum++;
            c += kep[gi_y[i]][gi_x[i]];
        }
        //cout<<kep[gi_y[i]][gi_x[i]]<<"\n";

    }
    cout << sum << " " << c * 2;



    return 0;
}
