#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int isValid(string s) {
            // code here

            int l=0;
            int r=0;
            int n=s.size();
            int no=0;

            vector<int>ans;

            while(r<n)
            {
                if(s[r]=='.')
                {   if((r-l)>=1){

                        //cout << no << ".";
                        ans.push_back(no);
                        l = r + 1;
                        no = 0;

                   }
                    else
                    {
                        return 0;
                    }
                }
                else if(r==l && (r+1)<n && s[l]=='0' && s[l+1]!='.')
                {return 0;}
                else if(s[r]<'0' || s[r]>'9' )
                {
                    return 0;
                }
                else
                {
                    no=10*no+(s[r]-'0');
                }


                r+=1;
            }
            if((r-l)>=1)
            ans.push_back(no);


            if(ans.size()<4 || ans.size()>4)
            return 0;

            for(int i=0;i<4;i++)
            {
                cout << ans[i] << ".";
                if(ans[i]>255)
                return 0;
            }


            return 1;

}

int main()
{

    string s;

    s = "0.0.0.0";

    isValid(s);
}