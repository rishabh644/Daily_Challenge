class Solution {
public:
   void merge(vector<int>&nums,int left,int mid,int right)
   {
      int start1=left;
      int start2=mid+1;

      // If the direct merge is already sorted
      if(nums[mid]<=nums[start2])
      {
        return;
      }

      // Two pointers to maintain start of bith arrays to merge

      while(start1<=mid && start2<=right)
      {

       // If element 1 is in right place

       if(nums[start1]<=nums[start2])
       {
        start1++;
       }
       else
       {

          int value=nums[start2];
          int index=start2;

          // shift all the elements between element 1 and element 2 right by 1

          while(index!=start1)
          {
            nums[index]=nums[index-1];
            index--;
          }

          nums[start1]=value;

          // Update all the pointers

          start1++;
          mid++;
          start2++;


       }



    }


   }



    void merge_sort(vector<int>&nums,int l,int h)
    {
        if(l<h)
        {

           int mid=(l+h)/2;

           merge_sort(nums,l,mid);
           merge_sort(nums,mid+1,h);

           merge(nums,l,mid,h);

        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;

        merge_sort(nums,i,j);

        return nums;
    }
};