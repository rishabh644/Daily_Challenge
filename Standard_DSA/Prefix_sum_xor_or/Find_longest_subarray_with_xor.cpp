// Longest Beautiful subarray

int longestSubarray(int n, vector<int> &arr) {
        // code here


        unordered_map<int,int>ump;


        ump[0]=-1;

        int xr=arr[0];

        ump[xr]=0;
        int i=1;

        int ans=0;

        while(i<n)
        {

            xr^=arr[i];

            if(ump.find(xr)!=ump.end())
            {
                ans=max(ans,i-ump[xr]);
            }
            else
            {
                ump[xr]=i;
            }

            i+=1;

        }

        return ans;
    }