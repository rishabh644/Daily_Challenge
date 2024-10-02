class Solution {
public:
    int longestSubstring(string s, int k)
    {
        if(s.size()==0 || k>s.size())
        return 0;

        int countMap[26]={0};
        int n=s.size();
        int result=0;

        for(int start=0;start<n;start++)
        {
            // reset the count map
            memset(countMap,0,sizeof(countMap));

            for(int end=start;end<n;end++)
            {
                countMap[s[end]-'a']++;
                if(isValid(s,start,end,k,countMap))
                {
                    result=max(result,end-start+1);
                }

            }

        }

        return result;

    }

    bool isValid(string s,int start,int end,int k,int countMap[26])
    {
        int countLetters=0,countAtLeastK=0;

        for(int i=0;i<26;i++)
        {
           if(countMap[i]>0)
           countLetters++;
           if(countMap[i]>=k)
           countAtLeastK++;

        }

        return countAtLeastK==countLetters;

    }

};
//////////////////////////---------------/////////////////////------------------------///////////////////////---------------------////////////////////------
class Solution {
public:
     int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstringUtil(s, 0, n, k);
    }
    int longestSubstringUtil(string &s, int start, int end, int k) {
        if (end < k) return 0;
        int countMap[26] = {0};
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
            return max(longestSubstringUtil(s, start, mid, k),
                    longestSubstringUtil(s, midNext, end, k));
        }
        return (end - start);
    }

};
/////////////////////------------------////////////////////---------------------------//////////////////////////////---------------------------////////////////////////////------------------------
