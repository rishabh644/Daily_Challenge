class NumArray {
private:
    vector<int> tree;
    vector<int>arr;
    int n;
public:
    int construct(int ss,int se,int si)
    {
        if(ss==se)
        {
            tree[si]=arr[ss];
            return tree[si];
        }
        int mid=(ss+se)/2;
        tree[si]=construct(ss,mid,2*si+1)+construct(mid+1,se,2*si+2);
       return tree[si];
    }
    NumArray(vector<int>& nums) {

        n=nums.size();

        int sz=4*n;
        tree=vector<int>(sz);
        arr=nums;
        construct(0,n-1,0);
    }
    void updatetree(int ss,int se,int index,int si,int diff)
    {
        if(index<ss || index>se)
        return;

        tree[si]+=diff;

        if(se>ss)
        {
            int mid=(ss+se)/2;
            updatetree(ss,mid,index,2*si+1,diff);
            updatetree(mid+1,se,index,2*si+2,diff);
        }
    }
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        updatetree(0,n-1,index,0,diff);
    }
    int getsum(int ss,int se,int l,int r,int si)
    {
        if(r<ss || l>se )
        return 0;

        if(l<=ss && r>=se)
        {
             return tree[si];
        }

        int mid=(ss+se)/2;

        return getsum(ss,mid,l,r,2*si+1)+getsum(mid+1,se,l,r,2*si+2);
    }

    int sumRange(int l, int r) {
        return getsum(0,n-1,l,r,0);
    }
};
