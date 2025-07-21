class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
      int j=-1;

      int i=0;

      while(i<nums.size())
      {
         if(nums[i]!=val)
         {
            nums[++j]=nums[i];
         }
         i+=1;
      }

      return ++j;

    }
};