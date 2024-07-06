// Minimum Operations to Make Binary Array
// Elements Equal to One I

// You are given a binary array nums.

// You can do the following operation on the array any number of times (possibly zero):

// Choose any 3 consecutive elements from the array and flip all of them.

// Flipping an element means changing its value from 0 to 1, and from 1 to 0.

// Return the minimum number of operations required to male all elements in nums equal
// to 1. It it is impossible, return -1.


class Solution {
public:
    int minOperations(vector<int>& nums) {

       int sz=nums.size(),res=0;

       for(int i=0;(i+2)<sz;++i)
         if(nums[i]==0){

            ++res;
            nums[i+1]=!nums[i+1];
            nums[i+2]=!nums[i+2];
         }

        return nums[sz-1] && nums[sz-2] ? res : -1;
    }
};