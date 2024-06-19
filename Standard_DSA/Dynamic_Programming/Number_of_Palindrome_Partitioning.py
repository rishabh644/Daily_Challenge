def add_all_valid_partition(self,i,j,s,current_path,ans,dp):
        if(j==len(s)):
            if(i==j):
                ans.append(current_path[:])
            return

        if(dp[i][j]==True):
            #I choose to partition at j
            current_path.append(s[i:j+1])
            self.add_all_valid_partition(j+1,j+1,s,current_path,ans,dp)
            current_path.pop()

        # I choose not to partition at j

        self.add_all_valid_partition(i,j+1,s,current_path,ans,dp)

    def partition(self, s: str) -> List[List[str]]:

       n=len(s)

       dp=[[False for _ in range(n)] for _ in range(n)]

       for i in range(n):
        dp[i][i]=True

       for length in range (2,n+1):
        for i in range(0,n-length+1):
            j=i+length-1
            if( s[i]==s[j] and ((j-i)==1 or dp[i+1][j-1]) ):
                dp[i][j]=True

       ans=[]
       current_path=[]
       i=0
       j=0

       self.add_all_valid_partition(i,j,s,current_path,ans,dp)

       return ans