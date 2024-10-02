class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                pq.push(abs(nums[j]-nums[i]));
            }
        }

        int ans;
        int pi=0;

        while(pi<(k-1))
        {
            pq.pop();
            pi+=1;
        }
        return pq.top();
    }
};
///////////////////////////////////////////////////////////---------------------------------------------------------------------------------------------//////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int number_of_pair(vector<int>&nums,int mid)
    {
         int n=nums.size();
         int count=0;
         int j=0;
         for(int i=0;i<n;++i)
         {
            while(j<n && nums[j]-nums[i]<=mid)
            {
                j++;
            }
            count+=j-i-1;
         }
         return count;
    }
    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1]-nums[0];
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int npr=number_of_pair(nums,mid);
            if(npr>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return ans;

    }
};