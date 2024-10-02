class Solution {
public:
    int search(vector<int>& nums, int target)
    {

        int n=nums.size();
        int left=0,right=n-1;

        //Find the index of the pivot element (the smallest element)

        while(left<=right)
        {
            int mid=(left+right)/2;

            if(nums[mid]>nums[n-1])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        int answer=binarySearch(nums,0,left-1,target);

        if(answer!=-1)
        {
            return answer;
        }

        // Binary search over elements on the pivot elements right

        return binarySearch(nums,left,n-1,target);

    }

    int binarySearch(vector<int>&nums,int leftBoundary,int rightBoundary,int target)
    {

        int left=leftBoundary;
        int right=rightBoundary;

        while(left<=right)
        {
            int mid=(left+right)/2;

            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }

        return -1;


    }


};
///////////////////////////////-------------------------///////////////////////////////----------------------------//////////////////////////////-------------------------
class Solution {
public:
    int search(vector<int>& nums, int target)
    {

        int n=nums.size();
        int left=0,right=n-1;

        while(left<=right)
        {

           int mid=(left+right)/2;

           // Case 1:Find target
           if(nums[mid]==target)
           {
            return mid;
           }
            // Case 2: Subarray on mid's left is sorted
           else if(nums[mid]>=nums[left])
           {
                if(target>=nums[left] && target<nums[mid])
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
           }
           // case 3: Subarray on mid's right is sorted
           else
           {

              if(target<=nums[right] && target>nums[mid])
              {
                left=mid+1;
              }
              else
              {
                right=mid-1;
              }

           }


        }

        return -1;

    }
};