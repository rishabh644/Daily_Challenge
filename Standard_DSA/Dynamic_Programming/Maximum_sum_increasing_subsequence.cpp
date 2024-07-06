int maxSumIS(int arr[], int n)
	{
	    // Your code goes here



	    vector<int>dp(n,0); // dp[i] represent maximum sum of increasing subsequece ending at i

	    dp[0]=arr[0];

	    for(int i=1;i<n;i++)
	    {
	        dp[i]=arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[j]+arr[i],dp[i]);
	            }
	        }
	    }


	    return *max_element(dp.begin(),dp.end());






	}