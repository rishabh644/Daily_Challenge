class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {

        priority_queue<int>pq(nums.begin(),nums.end());

        long long sum=0;
        int val;

        while(k>0)
        {
            val=pq.top();
            sum=sum+val;
            pq.pop();
            pq.push(ceil(val/3.0));
            k-=1;
        }

        return sum;

    }
};