class NumArray {
private:
    vector<int> tree;
    vector<int>arr;
    int n;
public:

    NumArray(vector<int>& nums) {
        n=nums.size();
        int sz=n+1;
        tree=vector<int>(sz,0);
        arr=vector<int>(n,0);

        for(int i=0;i<n;i++)
        update(i,nums[i]);

    }

    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;

        index=index+1;

        while(index<=n)
        {
            tree[index]+=diff;

            index=index+(index&(-1*index));
        }
    }
    int getsum(int i)
    {
        i=i+1;
        int res=0;

        while(i>0)
        {
            res=res+tree[i];
            i=i-(i&(-1*i));

        }

        return res;
    }

    int sumRange(int l, int r) {
        if(l==0)
        return getsum(r);
        else
        return getsum(r)-getsum(l-1);
    }
};