class Solution {
private:
    vector<int>dp;
public:
    int solve(int x, int y)
    {

        if(x<=y)
        return y-x;
        if(dp[x]!=-1)
        return dp[x];

        int res=abs(x-y);  // case 1

        res=min(res,1+x%5+solve(x/5,y)); // case 2
        res=min(res,1+(5-x%5)+solve(x/5+1,y)); // case 3
        res=min(res,1+x%11+solve(x/11,y)); // case 3
        res=min(res,1+(11-x%11)+solve(x/11+1,y)); // case 4
        return dp[x]=res;

    }

    public:
    int minimumOperationsToMakeEqual(int x,int y)
    {
          dp=vector<int>(10001,-1);
          return solve(x,y);

    }
};