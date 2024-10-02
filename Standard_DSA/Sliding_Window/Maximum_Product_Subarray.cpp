class Solution {
public:
    int maxProduct(vector<int>& nums)
    {

        int ans=INT_MIN;

        int i,j;
        int n=nums.size();

        for(i=0;i<n;i++)
        {
            int prod=1;
            for(j=i;j<n;j++)
            {
               prod*=nums[j];
               ans=max(ans,prod);
            }

        }

        return ans;
    }
};
//////////////
// Time Complexity is O(n^2)


class Solution {
public:
    int maxProduct(vector<int>& nums)
    {

       if(nums.size()==0)
       return 0;

       long long max_so_far=nums[0];
       long long min_so_far=nums[0];

       long long result=max_so_far;

       for(int i=1;i<nums.size();i++)
       {
            long long curr=nums[i];

            long long temp_max=max(curr,max(max_so_far*curr,min_so_far*curr));

            min_so_far=min(curr,min(max_so_far*curr,min_so_far*curr));

            // Update max_so_far after min_so_far to avoid overwriting it
            max_so_far=temp_max;

            if(min_so_far<0 && curr>(INT_MIN+1)/min_so_far)
            {
                max_so_far=1;
                min_so_far=1;
            }
            // Update the result with the maximum product found so far
            result=max(max_so_far,result);

       }


       return result;

    }
};
//////////////////////////// o(n)
