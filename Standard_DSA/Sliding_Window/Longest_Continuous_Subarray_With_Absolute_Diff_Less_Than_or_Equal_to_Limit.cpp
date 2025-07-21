#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
           int l=0;
           int h=0;

           int mxi=0;
           int mini=0;

           int n=nums.size();

           int ans=1;
           int k;

           while(h<n)
           {

              if(nums[h]<=nums[mini])
              {
                  if(abs(nums[h]-nums[mxi])>limit)
                  {
                      l=mxi+1;

                      k=l;
                      mxi=l;
                      mini=l;
                      while(k<=h)
                      {
                          if(nums[k]>=nums[mxi])
                          mxi=k;
                          if(nums[k]<=nums[mini])
                          mini=k;
                          k+=1;
                      }
                  }

                  mini=h;
              }
               if(nums[h]>=nums[mxi])
              {
                  if(abs(nums[h]-nums[mini])>limit)
                  {
                      l=mini+1;
                      k=l;
                      mxi=l;
                      mini=l;
                      while(k<=h)
                      {
                          if(nums[k]>=nums[mxi])
                          mxi=k;
                          if(nums[k]<=nums[mini])
                          mini=k;
                          k+=1;
                      }

                  }
                  mxi=h;
              }
              cout << " l: " << l << " h: " << h << endl;
              cout << " mxi: " << mxi<<" mini: " <<mini<< endl;
              cout << " mxi val: " <<nums[mxi]<<" mini val: " <<nums[mini]<< endl;
              ans=max(ans,h-l+1);
              cout<<"l "<<l<<" h "<<h<<"  ans "<<ans<<endl;
              h+=1;
           }

           return ans;
    }
};




int main()
{
    Solution obj;

    vector<int> vec = {24, 12, 71, 33, 5, 87, 10, 11, 3, 58, 2, 97, 97, 36, 32, 35, 15, 80, 24, 45, 38, 9, 22, 21, 33, 68, 22, 85, 35, 83, 92, 38, 59, 90, 42, 64, 61, 15, 4, 40, 50, 44, 54, 25, 34, 14, 33, 94, 66, 27, 78, 56, 3, 29, 3, 51, 19, 5, 93, 21, 58, 91, 65, 87, 55, 70, 29, 81, 89, 67, 58, 29, 68, 84, 4, 51, 87, 74, 42, 85, 81, 55, 8, 95, 39};
    int limit = 87;
    cout << "Longest Subarray " << obj.longestSubarray(vec, limit) << endl;

}