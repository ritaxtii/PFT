
#include <bits/stdc++.h>
using namespace std;
int game[6][6] = {};
void L()
{
    for (int i = 1; i <=4; i++)
    {
        for (int j = 1; j <=4; j++)
        {
            if (game[i][j] != 0)
            {
                int now = game[i][j];
                for (int k = j-1; k >= 0; k--)
                {
                    if (game[i][k] != 0)
                    {
                        if (game[i][k] != now)
                        {   
                            game[i][j] = 0;
                            game[i][k+1] = now;
                            break;
                        }
                        else
                        {   
                            game[i][j] = 0;
                            game[i][k] = now*2;
                            break;
                            
                        }
                    }
                    else if (k == 0)
                    {
                        game[i][j] = 0;
                        game[i][k+1] = now;
                        
                    }
                }
            }
        }
    }
}
void R()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 4; j >= 1; j--)
        {
            if (game[i][j] != 0)
            {
                int now = game[i][j];
                for (int k = j + 1; k <= 5; k++)
                {
                    if (game[i][k] != 0)
                    {
                        if (game[i][k] != now)
                        {
                            game[i][j] = 0;
                            game[i][k - 1] = now;
                            break;
                        }
                        else
                        {
                            game[i][j] = 0;
                            game[i][k] = now*2;
                            break;
                        }
                    }
                    else if (k == 5)
                    {
                        game[i][j] = 0;
                        game[i][k - 1] = now;
                    }
                }
            }
        }
    }
}
void U()
{
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 1; i <= 4; i++)
        {
            if (game[i][j] != 0)
            {
                int now = game[i][j];
                for (int k = i - 1; k >= 0; k--)
                {
                    if (game[k][j] != 0)
                    {
                        if (game[k][j] != now)
                        {
                            game[i][j] = 0;
                            game[k + 1][j] = now;
                            break;
                        }
                        else
                        {
                            game[i][j] = 0;
                            game[k][j] = now * 2;
                            break;
                        }
                    }
                    else if (k == 0)
                    {
                        game[i][j] = 0;
                        game[k + 1][j] = now;
                    }
                }
            }
        }
    }
}
void D()
{
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 4; i >= 1; i--)
        {
            if (game[i][j] != 0)
            {
                int now = game[i][j];
                for (int k = i + 1 ; k<=5; k++)
                {
                    if (game[k][j] != 0)
                    {
                        if (game[k][j] != now)
                        {
                            game[i][j] = 0;
                            game[k - 1][j] = now;
                            break;
                        }
                        else
                        {
                            game[i][j] = 0;
                            game[k][j] = now*2;
                            break;
                        }
                    }
                    else if (k == 5)
                    {
                        game[i][j] = 0;
                        game[k - 1][j] = now;
                    }
                }
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> game[i][j];
        }
    }
    string s;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i += 2)
    {
        if (s[i] == 'L') L();
        if (s[i] == 'R') R();
        if (s[i] == 'U') U();
        if (s[i] == 'D') D();

    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << game[i][j]<<" ";
        }
        cout << endl;
    }
}
