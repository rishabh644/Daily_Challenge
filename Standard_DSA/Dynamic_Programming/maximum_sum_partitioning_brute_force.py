def maxSumAfterPartitioning(arr,k):
    def dfs(i):
        if i<0:
            return 0
        max_sum=0
        current_max=0

        # Try partition lengths from 1 to k
        for j in range(1,k+1):
            if i -j +1>=0:
                current_max=max(current_max,arr[i-j+1])
                max_sum=max(max_sum,dfs(i-j)+current_max*j)

        return max_sum

    return dfs(len(arr)-1)


# Example usage:
arr=[1,15,7,9,2,5,10]
k=3
print(maxSumAfterPartitioning(arr,k))