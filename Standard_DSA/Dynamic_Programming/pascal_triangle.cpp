vector<vector<int>> generate(int numRows) {

      vector<vector<int>>ans;

      int n=1,k;
      int r;

      while(n<=numRows)
      {
        vector<int>temp;
        r=0;
        k=n-1;
        while(r<=k){

        if(k==0 || r==0 || r==k)
        {
            temp.push_back(1);
        }
        else
        {
            temp.push_back(ans[k-1][r-1]+ans[k-1][r]);
        }

        r+=1;
                  }
        ans.push_back(temp);

        n++;
    }

    return ans;

    }