int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here

        if(n<3)
        return 0;


        vector<int>lis_left(n,1);

        vector<int>lis_right(n,1);





        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && lis_left[i]<lis_left[j]+1)
                {
                    lis_left[i]=lis_left[j]+1;
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j] && lis_right[i]<lis_right[j]+1)
                {
                    lis_right[i]=lis_right[j]+1;
                }
            }
        }

        int ans=0;

        for(int i=1;i<=(n-2);i++)
        {
            if(lis_left[i]>1 && lis_right[i]>1)
            {
                ans=max(ans,lis_left[i]+lis_right[i]-1);
            }
        }


        return ans;

    }