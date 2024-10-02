class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int fre=1;
        int k=1;
        int i=1;
        int j=1;
        int n=nums.size();
        int lstm=nums[0];
        while(i<n)
        {
            if(nums[i]==lstm)
            {
                fre+=1;
            }
            else
            {
                fre=1;
                lstm=nums[i];
            }
            if(fre<=2)
            {
                int t=nums[j];
                nums[j]=nums[i];
                nums[i]=t;
                k++;
                j++;
            }
            i+=1;
        }

        return k;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()<3)
        return nums.size();

        // Initialize the counter
        int j=2;

        // start from the third element of the array and process
        // elements one by one

        for(int i=2;i<nums.size();i++)
        {
            // If the current element is not a duplicate
            if(nums[i]!=nums[j-2])
            {
                nums[j++]=nums[i];
            }

        }

        return j;

    }