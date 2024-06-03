#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int>&a,vector<int>&b)
{
      if(a[0]<b[0])
      return true;
      else
      return false;


}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end(),cmp);

        int i=0;

        int ans=0;
        int start=meetings[0][0];
        int end=meetings[0][1];

        int n=meetings.size();

        ans+=start-1;
     cout << " ans " << ans << endl;
        i = 1;
        while(i<n)
        {
            int ns=meetings[i][0];
             int ne=meetings[i][1];
             cout << "start " << start << " end " << end << endl;

             cout << "ns " << ns << endl;
             cout << " ne " << ne << endl;

             if (ns <= end)
             {
                 end = max(end, ne);
            }
            else
            {
                ans+=(ns-end-1);
                start=ns;
                end=ne;
            }
            cout << " ans " << ans << endl;
            i++;
        }

        if(end<days)
        ans+=days-end-1;

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> meetings = {{5, 7},
                                   {1, 3},
                                   {9, 10}};

    obj.countDays(10, meetings);
}