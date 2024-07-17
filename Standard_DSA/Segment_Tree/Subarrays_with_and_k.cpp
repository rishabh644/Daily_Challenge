class SegmentTree
{

    public:
    vector<int>root;
    int n,k;
    SegmentTree(vector<int>&nums,int k)
    {
       this->k=k;
       this->n=nums.size();

       root.resize(n*4);
       build(0,0,n-1,nums);
    }

    void build(int i,int left,int right,vector<int>&nums)
    {
          if(left==right)
          {
            root[i]=nums[left];
            return;
          }

          int mid=(left+right)/2;

          //int mid=left+(right-left)/2;

          build(i*2+1,left,mid,nums);
          build(i*2+2,mid+1,right,nums);
          root[i]=root[i*2+1]&root[i*2+2];
    }
    int get(int left,int right)
    {
        return get(0,0,n-1,left,right);
    }
    int get(int i,int left,int right,int start,int end)
    {
         if(left>end || right<start)
         return -1;

         if(left>=start && right<=end) return root[i];

         int mid=(left+right)/2;

         return get(i*2+1,left,mid,start,end)&get(i*2+2,mid+1,right,start,end);

    }
    int queries(int start)
    {
         int left=start,leftMost=-1,rightMost=-1,right=n-1;

         while(left<=right)
         {
            int middle=(left+right)/2;

            int val=get(start,middle);
            if(val<=k)
            {
                if(val==k)leftMost=middle;

                right=middle-1;
            }
            else
            left=middle+1;
         }

         if(leftMost==-1) return 0;
         left=leftMost,right=n-1;

         while(left<=right)
         {
           int mid=(left+right)/2;
           int val=get(start,mid);
           if(val<k) right=mid-1;
           else
           rightMost=mid,left=mid+1;

         }

         return rightMost-leftMost+1;

    }

    long long queries()
    {
        long long res=0;
        for(int i=0;i<n;i++)
        {
            res+=queries(i);
        }
        return res;
    }


};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

          SegmentTree root(nums,k);

          return root.queries();



    }
};