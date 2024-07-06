#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

      int ts=0;

      int i=0;

      int n=grumpy.size();

      for(i=0;i<n;i++)
      {
        if(grumpy[i]==0)
        {
            ts+=customers[i];
        }

      }
      int ct=0;
      int ans=ts;
      cout << "ANS at start " << ans << endl;
      for(int i=0;i<=(n-minutes);i++)
      {
        ct=0;
        for(int j=i;j<=(i+minutes-1);j++)
        {
           if(grumpy[j]==1)
           {
            ct+=customers[j];
           }
        }

        ans=max(ans,ts+ct);
        cout << "i " << i << " ans " << ans<<endl;
      }

      return ans;

    }
};


int main(){

    Solution obj;

    vector<int> customer = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    obj.maxSatisfied(customer, grumpy, minutes);
}