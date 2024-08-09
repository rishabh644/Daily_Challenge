class Solution {
public:
    int minimumPushes(string word) {

        int sz=word.size();


        if(sz<=8)
            return sz;

        if(sz>8 && sz<=16)
            return sz+(sz-8);
        if(sz>16 && sz<=24)
            return sz+(sz-8)+(sz-16);

        return sz+(sz-8)+(sz-16)+(sz-24);



    }
};

//////////////////////////////////////////////////////---------------------------------------------//////////////////////////////////////////////////////

class Cmp
{
   public:
   bool operator()(pair<char,int>&a,pair<char,int>&b)
   {
        return a.second<b.second;
   }

};

class Solution {
public:
    int minimumPushes(string word)
    {

        int sz=word.size();

        unordered_map<char,int>ump;

        int i,n=word.size();

        for(i=0;i<n;i++)
        {
            ump[word[i]]++;
        }

        priority_queue<pair<char,int>,vector<pair<char,int>>,Cmp>pq;

        for(auto mp=ump.begin();mp!=ump.end();mp++)
        {
            pq.push({mp->first,mp->second});
        }
        unordered_map<char,int>mci;
        int ind=1;
        while(!pq.empty())
        {
           pair<char,int>pr=pq.top();
           pq.pop();

           mci[pr.first]=ind;
           ind+=1;
        }

        int ans=0;

        for(auto ch:word)
        {
            if(mci[ch]<=8)
            ans+=1;
            else if(mci[ch]>8 && mci[ch]<=16)
            ans+=2;
            else if(mci[ch]>16 && mci[ch]<=24)
            ans+=3;
            else
            ans+=4;

        }

        return ans;
    }
};