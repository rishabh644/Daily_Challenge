class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int d)
    {

          for(int i=0;i<nums.size();i++)
          {

             for(int j=i+1;j<=i+k && j<nums.size();j++)
             {
                if(abs(nums[i]-nums[j])<=d)
                return true;
             }

          }

          return false;


    }
};
///////////////////------------/////////////////////----------------------//////////////////////----------------------//////////////////////////
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int d)
    {

          set<int>st;

          for(int i=0;i<nums.size();++i)
          {
             // Find the successor of current element

             auto s=st.lower_bound(nums[i]);

             if(s!=st.end() && *s<=nums[i]+d)
             return true;


             //Find the presecessor of current element
             if(s!=st.begin())
             {
                auto g=prev(s);
                if(nums[i]<=*g+d)
                return true;
             }

             st.insert(nums[i]);

             if(st.size()>k)
             st.erase(nums[i-k]);

          }

        return false;
    }
};
////////////////////////////////////----------------------//////////////////////////////////////------------------------------------///////////////////////////--------------------//////////////////////
class Solution {
public:

    long getID(long x,long w)
    {
        return x<0?(x+1)/w - 1:x/w;
    }


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if(t<0)
        return false;

        unordered_map<long,long>buckets;

        long w=(long)t+1;

        for(int i=0;i<nums.size();++i)
        {

            long long bucket=getID(nums[i],w);

            //Check if current bucket is empty, each bucket may contain at most
            // one element

            if(buckets.count(bucket))
            return true;

            // check the neighbor buckets for almost duplicate

            if(buckets.count(bucket-1) && abs(nums[i]-buckets[bucket-1])<w)
            return true;

            if(buckets.count(bucket+1) && abs(nums[i]-buckets[bucket+1])<w)
            return true;

            // Now bucket is empty and no almost duplicate in neighbor buckets
            buckets[bucket]=(long)nums[i];

            if(i>=k)
            {
                buckets.erase(getID(nums[i-k],w));
            }

        }

        return false;

    }
};
//////////////////-------------------///////////////////-----------------//////////////////--------------------/////////////////////////----------------------------////////////////////////
class Solution {
public:

    long getID(long x,long w)
    {
        return x<0?(x)/w - 1:x/w;


    }


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if(t<0)
        return false;

        unordered_map<long,long>buckets;

        long w=(long)t+1;

        for(int i=0;i<nums.size();++i)
        {

            long long bucket=getID(nums[i],w);

            //Check if current bucket is empty, each bucket may contain at most
            // one element

            if(buckets.count(bucket))
            return true;

            // check the neighbor buckets for almost duplicate

            if(buckets.count(bucket-1) && abs(nums[i]-buckets[bucket-1])<w)
            return true;

            if(buckets.count(bucket+1) && abs(nums[i]-buckets[bucket+1])<w)
            return true;

            // Now bucket is empty and no almost duplicate in neighbor buckets
            buckets[bucket]=(long)nums[i];

            if(i>=k)
            {
                buckets.erase(getID(nums[i-k],w));
            }

        }

        return false;

    }
};

///////////////////////////////////////////---------------------------------------------------/////////////////////////////////////////////--------------------------------------------------//////////////////////////////////---------------------------------////////////////////////////////
