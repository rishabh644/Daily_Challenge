class Solution{
    public:

    bool bothmatch(vector<int>&allst,vector<int>&checkst)
    {
        bool alp=true;

        for(int i=0;i<256;i++)
        {
            if(allst[i]==1 && checkst[i]==0)
            {
                alp=false;
                break;
            }
        }

        return alp;
    }

    int findSubString(string str)
    {
        // Your code goes here

        int n=str.size();

        vector<int>allst(256,0);

        for(auto ch:str)
        {
            allst[ch]=1;
        }

        int ans=n;

        for(int i=0;i<n;i++)
        {
            vector<int>checkst(256,0);

            for(int j=i;j<n;j++)
            {
                checkst[str[j]]=1;

                if(bothmatch(allst,checkst))
                ans=min(ans,j-i+1);
            }
        }

        return ans;

    }
};
/////////////
    int findSubString(string str)
    {
        // Your code goes here

        vector<int>cnt(256,0);
        int count=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            int ind=str[i];
            if(cnt[ind]==0)
            count+=1;
            cnt[ind]++;
        }
        for(int i=0;i<256;i++)
        {
             if(cnt[i]!=0)
             {
                 cnt[i]=0;
             }
        }
        int ans=str.size();
        int match=0;
        int l=0;
        for(int i=0;i<str.size();i++)
        {

            int in=(int)str[i];
            if(cnt[in]==0)
            match+=1;
            cnt[in]++;
            if(match>=count)
            {

                while(l<i)
                {

                   if(cnt[str[l]]>1)
                   {
                      cnt[str[l]]-=1;
                      l++;
                   }
                   else
                   break;
                }
                ans=min(ans,i-l+1);
            }

        }

        return ans;

    }