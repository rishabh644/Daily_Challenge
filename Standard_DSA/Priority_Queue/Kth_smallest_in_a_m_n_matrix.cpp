class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        priority_queue<int>pq;

        for(int i=1;i<=m;i++)
        {

            for(int j=1;j<=n;j++)
            {
                pq.push(i*j);
                if(pq.size()>k)
                pq.pop();
            }

        }

        return pq.top();
    }
};