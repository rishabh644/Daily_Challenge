class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq;

        for(auto vl:stones)
        pq.push(vl);

        while(!pq.empty())
        {
            int a=pq.top();
            pq.pop();

            if(pq.empty())
            return a;

            int b=pq.top();
            pq.pop();

            if(a>b)
            {
                pq.push(a-b);
            }
            else if(b>a)
            {
                pq.push(b-a);
            }


        }

        return 0;
    }
};