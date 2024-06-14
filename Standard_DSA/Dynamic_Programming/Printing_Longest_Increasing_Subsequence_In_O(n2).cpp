vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here

        vector<int>dp(n,1);
        vector<int>path(n);

        for(int i=0;i<n;i++)
        {
            path[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if( arr[i]>arr[j] && dp[i]<(dp[j]+1) )
                {
                    dp[i]=dp[j]+1;
                    path[i]=j;
                }
            }
        }

        auto itr=max_element(dp.begin(),dp.end());

        int index=distance(dp.begin(),itr);

        vector<int>ans;

        ans.push_back(arr[index]);



        while(index!=path[index])
        {
            index=path[index];
            ans.push_back(arr[index]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }