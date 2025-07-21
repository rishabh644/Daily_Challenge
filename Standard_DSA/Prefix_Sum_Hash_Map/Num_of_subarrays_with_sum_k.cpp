class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        dr={0:1}
        psum=ans=0
        for vl in nums:
            psum+=vl
            ans+=dr.get(psum-k,0)
            dr[psum]=dr.get(psum,0)+1
        return ans
///////
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {

        int ans=0,psum=0;

        unordered_map<int,int>ump;
        ump[0]=1;

        for(auto vl:nums)
        {
            psum+=vl;
            ans+=ump[psum-k];
            ump[psum]+=1;
        }

        return ans;
    }
};