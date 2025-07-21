

class NumMatrix {
private:
    int sz;
    vector<int>arr;
    int segsz;
    int m,n;
    vector<int>segarr;
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        m=matrix.size();
        n=matrix.size();
        sz=m*n;
        arr.resize(sz);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i*n+j]=matrix[i][j];
            }
        }

        segsz=4*sz;
        segarr.resize(segsz);
        construct_seg(0,0,sz-1);

    }

    int construct_seg(int ind,int l,int h)
    {
        if(l==h)
        {
            segarr[ind]=arr[l];
            return segarr[ind];
        }

        int mid=(l+h)/2;

        segarr[ind]=construct_seg(2*ind+1,l,mid)+construct_seg(2*ind+2,mid+1,h);

        return segarr[ind];
    }
    void update_seg(int ind,int upi,int l,int h,int up)
    {
          if(upi<l || upi>h)
          return;


          segarr[ind]=segarr[ind]+up;

          if(l==h)
          return;

          int mid=(l+h)/2;

          update_seg(2*ind+1,upi,l,mid,up);
          update_seg(2*ind+2,upi,mid+1,h,up);

    }



    void update(int row, int col, int val)
    {
        int ind=row*n+col;
        int up=val-arr[ind];
        arr[ind]=val;
        update_seg(0,ind,0,sz-1,up);

    }

    int mysum(int ind,int ql,int qh,int l,int h)
    {
         if(qh<l || h<ql)
         return 0;

         if(ql<=l && h<=qh)
         return segarr[ind];

         int mid=(l+h)/2;

         return mysum(2*ind+1,ql,qh,l,mid)+mysum(2*ind+2,ql,qh,mid+1,h);

    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int low=row1*n+col1;
        int high=row2*n+col2;


        return mysum(0,low,high,0,sz-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */