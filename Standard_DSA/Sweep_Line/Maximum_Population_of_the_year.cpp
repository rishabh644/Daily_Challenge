class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        map<int,int>mp;

        for(auto vec:logs)
        {
            mp[vec[0]]++;
            mp[vec[1]]--;
        }
        int yr,al=0;
        int mal=0;
        for(auto pr:mp)
        {
            al+=pr.second;

            if(al>mal)
            {
                mal=al;
                yr=pr.first;
            }

        }

        return yr;


    }
};
///----O(n)
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        map<int,int>mp;

        for(auto vec:logs)
        {
            mp[vec[0]]++;
            mp[vec[1]]--;
        }
        int yr,al=0;
        int mal=0;
        for(auto pr:mp)
        {
            al+=pr.second;

            if(al>mal)
            {
                mal=al;
                yr=pr.first;
            }

        }

        return yr;


    }
};
///////////////////
