#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int secondsToRemoveOccurrences(string S)
    {
        int i,k=0;
        int n=S.size();
        i=0;
        bool exist;

        while(true)
        {

            exist=false;
            i=0;
            k+=1;

            while(i<n)
            {
              if(i<(n-1) && S[i]=='0' && S[i+1]=='1')
              {
                S[i]='1';
                S[i+1]='0';
                exist=true;
                i+=2;
              }
              else
              {
              i+=1;
              }

            }

            cout<<S<<endl;

            if(exist==false)
            {
                break;
            }


        }

        return k-1;

    }
};





int main()
{
    Solution obj;
    string s;

    cin>>s;

    cout << endl;
    cout<<obj.secondsToRemoveOccurrences(s)<<endl;

    return 0;
}