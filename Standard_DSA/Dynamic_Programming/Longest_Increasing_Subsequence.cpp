int modified_binary_search(int tail[],int l,int h,int vl)
{
  int ans=h;
  int mid;

  while(l<=h)
  {
        mid=(l+h)/2;
        if(vl<=tail[mid])
        {
            ans=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }

  }


  return ans;

}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

      int n=nums.size();

      int tail[n];

      tail[0]=nums[0];

      // tail[i] store the minimum possible tail value of lenghth i+1

      int l=1,i,pos;

      for(i=1;i<n;i++)
      {
          if(nums[i]>tail[l-1])
          {
              tail[l]=nums[i];
              l+=1;
          }
          else
          {
              pos=modified_binary_search(tail,0,l-1,nums[i]);
              tail[pos]=nums[i];
          }
      }



  return l;

    }
};