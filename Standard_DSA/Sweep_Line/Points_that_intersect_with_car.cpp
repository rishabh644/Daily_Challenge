class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        unordered_set<int>ust;

        int i;
        int j;

        for(i=0;i<nums.size();i++)
        {
            for(j=nums[i][0];j<=nums[i][1];j++)
            {
                ust.insert(j);
            }
        }

        return ust.size();




    }
};