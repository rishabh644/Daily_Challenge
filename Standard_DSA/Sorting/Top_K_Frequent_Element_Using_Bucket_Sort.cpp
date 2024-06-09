#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    // freq unordered_map

    unordered_map<int,int>ump;

    int n=nums.size();

    for(int no:nums)
    {
        ump[no]+=1;
    }

    vector<vector<int>>bucket(n+1);

    for(auto it=ump.begin();it!=ump.end();it++)
    {
        bucket[it->second].push_back(it->first);
    }

    vector<int>res;

    for(int i=bucket.size()-1;i>=0;i--){
        for(auto it:bucket[i])
        {
            res.push_back(it);
            if(res.size()>=k)
            return res;
        }
    }

    return res;

}

int main()
{
}