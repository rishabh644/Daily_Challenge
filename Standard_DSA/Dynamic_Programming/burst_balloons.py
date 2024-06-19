class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        #Padding nums with 1 at both ends
        new_nums=[1]+nums+[1]
        n=len(nums)

        # DP table
        dp=[[0]*(n+2) for _ in range(n+2)]

        #Fill the table
        for length in range(1,n+1):
            # length of the subarray
            for left in range(1,n-length+2):
                right=left+length-1 # ending point of the subarray
                for i in range(left,right+1):
                     # position of the last ballon to burst in subarray
                    dp[left][right]=max(dp[left][right],new_nums[left-1]*new_nums[i]*new_nums[right+1]+dp[left][i-1]+dp[i+1][right])

        #Step 4: Return the result
        return dp[1][n]