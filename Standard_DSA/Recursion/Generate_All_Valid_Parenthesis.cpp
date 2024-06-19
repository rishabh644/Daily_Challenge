#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void generate_parenthesis(int i,int opn,int cls,int n,string temp,vector<string>&ans)
    {
        if(i>=2*n)
        {
            ans.push_back(temp);
            return;
        }
        if(opn<n)
        {
            generate_parenthesis(i+1,opn+1,cls,n,temp+'(',ans);
        }
        if(opn>cls && cls<n)
        {
            generate_parenthesis(i+1,opn,cls+1,n,temp+')',ans);
        }

    }


vector<string> AllParenthesis(int n)
    {
        // Your code goes here


        int pos=2*n;

        int opn=0;
        int cls=0;

        string temp="";

        vector<string>ans;

        int i=0;

        generate_parenthesis(i,opn,cls,n,temp,ans);


        return ans;

    }
