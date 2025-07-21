int maxSumIS(int arr[], int n)
	{
	    // Your code goes here

	    vector<int>dp(n,0);



	    for(int i=0;i<n;i++)
	    {   dp[i]=arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(dp[i]>dp[j])
	            {
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	            }
	        }
	    }

	    int ans=dp[0];

	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,dp[i]);
	    }

	    return ans;
	}