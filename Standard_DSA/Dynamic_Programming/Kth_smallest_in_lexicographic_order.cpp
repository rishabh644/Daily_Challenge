class Solution {
public:

    void dfs(int prevn,int n,int k,vector<int>&ans)
    {
        ans.push_back(prevn);

        if(ans.size()>=k)
        return;

       for(int j=0;j<=9;j++)
       {

         int newn=prevn*10+j;
         if(newn>n)
         break;

         dfs(newn,n,k,ans);

       }

    }


    int findKthNumber(int n, int k)
    {

        vector<int>ans;

        for(int i=1;i<=9;i++)
        {
            int curno=i;

            dfs(curno,n,k,ans);
        }

        return ans[k-1];
    }
};
////////////////////
class Solution {
public:

    int findKthNumber(int n,int k)
    {
       int curr=1;
       k--;

       while(k>0)
       {

          int step=countSteps(n,curr,curr+1);

          if(step<=k)
          {
            curr++;
            k-=step;
          }
          else
          {
            curr*=10;
            k--;
          }

       }

       return curr;

    }

    private:
    int countSteps(int n,long prefix1,long prefix2)
    {
        int steps=0;

        while(prefix1<=n)
        {
            steps = steps+min((long)(n+1),prefix2)-prefix1;
            prefix1*=10;
            prefix2*=10;
        }

        return steps;
    }

};