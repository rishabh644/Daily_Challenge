# You are given an r rows and c cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

# You have two robots that can collect chocolates for you:

# Robot #1 is located at the top-left corner (0, 0), and
# Robot #2 is located at the top-right corner (0, cols - 1).
# Return the maximum number of chocolates collection using both robots by following the rules below:

# From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
# When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
# When both robots stay in the same cell, only one takes the chocolates.
# Both robots cannot move outside of the grid at any moment.
# Both robots should reach the bottom row in grid.

## Brute Force Approach ##

class Solution:

    mov=[(1,-1),(1,0),(1,1)]

    def dfs(self,i,j,n,m,pathsA,currpath,visited):
        if (i,j) in visited:
            return
        if (i<0 or j<0 or i>=n or j>= m):
            return

        if i==n-1:
            currpath.append((i,j))
            pathsA.append(currpath.copy())
            currpath.pop()

        visited.add((i,j))

        currpath.append((i,j))

        for item in self.mov:
            self.dfs(i+item[0],j+item[1],n,m,pathsA,currpath,visited)

        currpath.pop()
        visited.remove((i,j))


    def summ(self,pathA,pathB,grid):
        ttl=0
        visited=set()
        for item in pathA:
            ttl+=grid[item[0]][item[1]]
            visited.add(item)

        for item in pathB:
            if item not in visited:
                ttl+=grid[item[0]][item[1]]

        return ttl


    def solve(self, n, m, grid):
        # Code here

        # DFS from (0,0)

        pathsA=[]
        currpath=[]
        visited=set()

        self.dfs(0,0,n,m,pathsA,currpath,visited)

        # DFS from (0,m-1)

        pathsB=[]


        self.dfs(0,m-1,n,m,pathsB,currpath,visited)

        ans=0
        for pathA in pathsA:
            for pathB in pathsB:
                ans=max(ans,self.summ(pathA,pathB,grid))

        return ans