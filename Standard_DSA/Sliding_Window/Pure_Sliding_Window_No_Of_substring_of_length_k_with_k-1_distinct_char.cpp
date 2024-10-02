    int countOfSubstrings(string S, int K) {
        // code here

        vector<int>freq(26,0);

        auto ind=[](char ch){
            return ch-97;
        };

        int n=S.size();
        int dst=0;

        for(int i=0;i<K;i++)
        {
            freq[ind(S[i])]++;
            if(freq[ind(S[i])]==1)
            dst+=1;
        }

        int cnt=0;

        if(dst==K-1)
        cnt+=1;

        int j=K;
        int i=0;
        while(j<n)
        {
            freq[ind(S[i])]-=1;
            if(freq[ind(S[i])]==0)
            dst-=1;

            freq[ind(S[j])]+=1;
            if(freq[ind(S[j])]==1)
            dst+=1;

            if(dst==K-1)
            cnt+=1;
            i+=1;
            j+=1;
        }

        return cnt;
    }