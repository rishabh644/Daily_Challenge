class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {

     for(int i=0;i<nums.size();i++)
     {
        for(int j=i+1;j<=i+k && j<nums.size();j++)
        {
             if(nums[i]==nums[j])
             return true;
        }
     }

     return false;

    }
};

///////////////////////////////---------///////////////////-----------------///////////////////------------------------////////////////////
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {

     unordered_set<int>st;

     for(int i=0;i<nums.size();i++)
     {
        if(st.find(nums[i])!=st.end())
        return true;

        st.insert(nums[i]);

        if(st.size()>k)
        st.erase(nums[i-k]);

     }


     return false;
    }
};
//////////////////
