#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Compare{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;

        for(auto n:nums)
        {
            ump[n]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;

        for(auto it=ump.begin();it!=ump.end();it++)
        {
            pq.push({it->first,it->second});
        }
        vector<int>ans;

        while(ans.size()<k)
        {
            auto pr=pq.top();
            pq.pop();
            ans.push_back(pr.first);
        }
        return ans;
    }
};

int main()
{
    vector<int> temp = {1, 1, 1, 1, 1, 2, 2, 3, 8, 8, 8, 9, 8, 8, 8, 8, 8};

    Solution obj;

    vector<int> ans = obj.topKFrequent(temp, 3);

    for(auto vl:ans)
    {
        cout << vl << endl;
    }

    return 0;
}