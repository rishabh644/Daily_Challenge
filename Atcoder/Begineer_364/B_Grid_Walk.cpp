#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int m, n;
    string s;
    cin >> m >> n;

    int x, y;

    cin >> x >> y;

    vector<vector<char>> mat(m, vector<char>(n, '.'));

    for (int i = 0; i < m;i++)
    {

        for (int j = 0; j < n;j++)
        {
            cin >> mat[i][j];
        }

    }
    cin >> s;
    x = x - 1;
    y = y - 1;

    for (int i = 0; i < s.size();i++)
    {
        int X, Y;
        if (s[i] == 'L')
        {
            X = x;
            Y = y - 1;

            if(Y>=0 && mat[X][Y]=='.')
            {
                x = X;
                y = Y;
            }

        }
        else if(s[i]=='U')
        {
           X = x-1;
            Y = y;

            if(X>=0 && mat[X][Y]=='.')
            {
                x = X;
                y = Y;
            }
        }
        else if(s[i]=='R')
        {
          X = x;
            Y = y + 1;

            if(Y<n && mat[X][Y]=='.')
            {
                x = X;
                y = Y;
            }
        }
        else
        {
            X = x+1;
            Y = y;

            if(X<m && mat[X][Y]=='.')
            {
                x = X;
                y = Y;
            }

        }

    }

    cout << x+1 << " " << y+1 << endl;

    return 0;
}