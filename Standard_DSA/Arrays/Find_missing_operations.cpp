class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int m=rolls.size();

        int tsum=mean*(n+m);

        int rsum;
        int csum=0;

        for(auto vl:rolls)
        {
            csum+=vl;
        }

        rsum=tsum-csum;


        if(rsum>6*n || rsum<n)
        return {};

        vector<int>ans(n,1);

        rsum-=n;
        int i=0;
        while(i<n && rsum>0)
        {
            while( ans[i]<6 && rsum>0)
            {
                ans[i]+=1;
                rsum-=1;
            }

            i+=1;
        }

        return ans;

    }
};