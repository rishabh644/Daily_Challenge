vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return intersect(nums2,nums1);
        }

        unordered_map<int,int>ump;

        int i=0;
        while(i<nums1.size())
        {
            ump[nums1[i]]++;
            i+=1;
        }
        vector<int>ans;
        for(auto vl:nums2)
        {
            if(ump[vl]>0)
            {
                ans.push_back(vl);
            }
            ump[vl]-=1;
        }

        return ans;
    }
};