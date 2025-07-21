#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    string s;

    cin >> s;

    string ans = "";

    int i = 1;
    int n = s.size();

    int j = 0;

    while(i<n)
    {
        while(i<n && s[i]==s[i-1])
        {

            i += 1;

        }
        int cnt = i - j;
        if(cnt>1)
        {
            ans = ans+to_str(cnt) + s[j];
        }
        else
        {
            ans = ans + s[j];
        }
        j = i;
    }

    cout << ans << endl;
}