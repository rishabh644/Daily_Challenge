class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n=nums.size();
        int left=0;
        int right=n-1;

        while(left<=right)
        {
            int mid=(left+right)/2;

            if(nums[mid]>nums[n-1])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }

        }

        return nums[left];

    }
};