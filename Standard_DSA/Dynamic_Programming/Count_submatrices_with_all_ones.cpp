class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m,n=len(mat),len(mat[0])

        height=[[0]*n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if mat[i][j]==1:
                    if i==0:
                        height[i][j]=1
                    else:
                        height[i][j]=height[i-1][j]+1
        # Step 2:Calculate the number of submatrices with all ones
        result=0
        for i in range(m):
            for j in range(n):
                if mat[i][j]==1:
                    min_height=height[i][j]
                    for k in range(j,-1,-1):
                        if height[i][k]==0:
                            break
                        min_height=min(min_height,height[i][k])
                        result+=min_height
        return result
