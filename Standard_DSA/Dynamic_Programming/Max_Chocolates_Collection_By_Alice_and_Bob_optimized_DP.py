
def maxChocolates(grid):
    r,c=len(grid),len(grid[0])

    dp=[[[0]*c for _ in range(c)] for _ in range(r)]

    # Initialize the base case (last row)

    for j1 in range(c):
        for j2 in range(c):
            if j1==j2:
                dp[r-1][j1][j2]=grid[r-1][j1]
            else:
                dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2]

    # Fill the dp table from bottom to top

    for i in range(r-2,-1,-1):
        for j1 in range(c):
            for j2 in range(c):
                max_chocolates=0
                for dj1 in [-1,0,1]:
                    for dj2 in [-1,0,1]:
                        nj1,nj2=j1+dj1,j2+dj2
                        if  0<=nj1<c and 0<=nj2<c:
                            if j1==j2:
                                current_chocolates=grid[i][j1]
                            else:
                                current_chocolates=grid[i][j1]+grid[i][j2]
                            max_chocolates=max(max_chocolates,current_chocolates+dp[i+1][nj1][nj2])

            dp[i][j1][j2]=max_chocolates

    return dp[0][0][c-1]
