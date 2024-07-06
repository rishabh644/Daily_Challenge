int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end(),mycmp);

        int cnt=1;
        int end=pairs[0][1];

        int i=1;

        int n=pairs.size();

        while(i<n)
        {
            if(end<pairs[i][0])
            {
                end=pairs[i][1];
                cnt+=1;
            }

            i+=1;

        }

        return cnt;

    }
};
