

// Classical DP appraoch
// int n=nums.size()
// vector<int>dp(n,1)

// int lengthofLIS(vector<int>&nums)
// {
//     int n = nums.size();

//     vector<int> dp(n, 1);

//     for (int i = 0; i < n;i++)
//     {

//         for (int j = 0; j < i;j++)
//         {
//              if(nums[i]>nums[j] && dp[i]<(dp[j]+1))
//              {
//                  dp[i] = dp[j] + 1;
//              }
//         }

//     }

//     return *max_element(dp.begin(),dp.end());
// }

/////////////////////////*************************************////////////////////////////////
    int lengthOfLIS(vector<int>& nums) {

      vector<int>sub;

      for(int x:nums) {

           if(sub.empty() || sub[sub.size()-1]<x){
            sub.push_back(x);
           }  else {
            auto it=lower_bound(sub.begin(),sub.end(),x);
            //Find the index of the first element>=x
            *it=x;
           }

      }



      return sub.size();

    }

////////////////////////***********************************************/////////////////////////
// class Solution {
// public:

//     int my_lower_bound(vector<int>sub,int x)
//     {
//         int l=0;
//         int r=sub.size()-1;
//         int mid;
//         //int ans;
//         while(l<=r)
//         {
//                 mid=(l+r)/2;
//                 if(sub[mid]>=x)
//                 {
//                     //ans=mid;
//                     r=mid-1;
//                 }
//                 else
//                 {
//                     l=mid+1;
//                 }
//         }
//         return r+1;
//     }

//     int lengthOfLIS(vector<int>& nums) {
//       vector<int>sub;
//       for(int x:nums) {
//            if(sub.empty() || sub[sub.size()-1]<x){
//             sub.push_back(x);
//            }  else {
//             int ind=my_lower_bound(sub,x);
//             sub[ind]=x;
//            }

//       }



//       return sub.size();

//     }
// };

//////////////////////////////////////////***********************************************///////////////////////////////
