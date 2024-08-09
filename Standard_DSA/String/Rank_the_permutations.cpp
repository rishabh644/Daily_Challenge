#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool cmp(string copy,string str)
{
    int i=0,j=0;

    int n=copy.size();

    while(i<n && j<n)
    {
        if(copy[i]!=str[j])
        return false;

        i+=1;
        j+=1;

    }

    return true;
}

class Solution{
  public:
    long long findRank(string str) {
        //code here

        string copy=str;

        sort(copy.begin(),copy.end());

        long long rank=1;

        do
        {

            cout << copy << endl;

            if(cmp(copy,str))
            {
                return rank;
            }


            rank+=1;

        }while(next_permutation(copy.begin(),copy.end()));

        return rank;
    }
};


int main(){

    Solution obj;

    int rank=obj.findRank("cabdefgh");

    cout << rank << endl;

    return 0;
}