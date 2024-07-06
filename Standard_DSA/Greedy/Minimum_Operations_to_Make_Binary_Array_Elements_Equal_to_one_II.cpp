
You are given a binary array nums.

You can do the following operation on the array any
number of time(possibly zero):

* Choose any index i from the array and flip all the
elements from index i to the end of the array.

Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1.





class Solution {

 public:
    int minOperations(vector<int>&nums) {

        int flag = 1;

        int count = 0, n = nums.size();

        for (int i = 0; i < n;i++)
        {
            if(nums[i]!=flag){
                count++;
                flag=!flag
                }


        }

        return count;
                                            }
};