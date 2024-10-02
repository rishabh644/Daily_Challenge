lass Solution {
  public:
    int lps(string str) {
        // Your code goes here

        int n=str.size();
        int ans=0;
        vector<int>lps(n,0);
        int q=0;
        for(int i=1;i<n;i++)
        {
            while(q>0 && str[q]!=str[i])
            q=lps[q-1];

            if(str[q]==str[i])
            {
                q=q+1;
            }
            lps[i]=q;
            ans=max(ans,lps[i]);
        }

        return ans;

    }
};