class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        priority_queue<int>pq;
        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {
           int dis=abs(queries[i][0])+abs(queries[i][1]);
           pq.push(dis);
           if(pq.size()>k)
           pq.pop();
           if(pq.size()<k)
           ans.push_back(-1);
           else
           ans.push_back(pq.top());

        }


        return ans;
    }
};