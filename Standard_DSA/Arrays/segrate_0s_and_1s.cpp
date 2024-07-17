void segregate0and1(vector<int> &arr) {
        // code here

        int pos=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                ++pos;
                int t=arr[pos];
                arr[pos]=arr[i];
                arr[i]=t;
            }
        }
    }