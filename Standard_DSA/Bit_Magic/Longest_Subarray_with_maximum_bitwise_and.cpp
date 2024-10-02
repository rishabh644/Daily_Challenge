class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i,j,n=nums.size();
        int ans=nums[0];
        int mxlen=1;
        for(i=0;i<n;i++)
        {
            int sub=nums[i];

            for(j=i;j<n;j++)
            {
                 sub=sub&nums[j];
                 if(sub>ans)
                 {
                    mxlen=j-i+1;
                    ans=sub;
                 }
                 else if(sub==ans)
                 {
                    mxlen=max(mxlen,j-i+1);
                 }

            }

        }

        return mxlen;

    }
};
////////////////////////////
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i,j,n=nums.size();
        int ans=1;
        int max_val=nums[0];
        int current_streak=1;

        for(int i=1;i<n;i++)
        {
            if(nums[i]>max_val)
            {
                 current_streak=1;
                 max_val=nums[i];
                 ans=1;
            }
            else if(nums[i]==max_val)
            {
                 if(nums[i]==nums[i-1])
                 {

                   current_streak+=1;
                   ans=max(ans,current_streak);

                 }
                 else
                 {
                    current_streak=1;
                 }

            }
            else
            {
               current_streak=1;
            }

        }


        return ans;



    }
};
///////////////////////////////////