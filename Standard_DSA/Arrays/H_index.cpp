class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n=citations.size();

        int h=n;

        while(h>=1)
        {
            int cnt=0;
            int i=0;
            while(i<n)
            {
               if(citations[i]>=h)
               cnt+=1;
               i+=1;
            }

            if(cnt>=h)
            return h;

            h-=1;
        }

        return h;

    }
};
////////////////////////////////////////////
class Solution {
public:
    int hIndex(vector<int>& citations)
    {

        sort(citations.begin(),citations.end(),greater<int>());

        int i=0;
        int n=citations.size();

        while(i<n && citations[i]>i)
        {
            i++;
        }

        return i;

    }
};
//////////////////////////////////////////////////////////////////////
