class Solution {
public:
    string minWindow(string s, string t)
    {
         if(s.size()==0 || t.size()==0)
         return "";

         // Dictionary which keeps a count of all the unique characters in t

        unordered_map<char,int>dicT;

        for(int i=0;i<t.length();i++)
        {
            dicT[t[i]]++;
        }

        // Number of unique characters in t, which need to be present in
        // the desired window

        int required=dicT.size();
        // left and right pointer
        int l=0,r=0;
        // formed is used to keep track of how many unique charcters in t
        // are present in the current window in its desored frequency
        // e.g. if t is "AABC" then the window must have two A's,one B and one
        // C. This formed would be=3 when all these conditions are met

        int formed=0;

        // Dictionary which keeps a count of all the uniqie characters in
        // the current window

        unordered_map<char,int>windowCounts;

        // ans list of the form (window length,left,right)
        int ans[3]={-1,0,0};

        while(r<s.length())
        {
            char c=s[r];
            windowCounts[c]++;

            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1

            if(dicT.find(c)!=dicT.end() && windowCounts[c]==dicT[c])
            {
                formed++;
            }

            // Try and contract the window till the point where ut ceases to be
            // desireable

            while(l<=r && formed==required)
            {
                c=s[l];

                if(ans[0]==-1 || r-l+1<ans[0])
                {
                    ans[0]=r-l+1;
                    ans[1]=l;
                    ans[2]=r;
                }

                // The chracter at the position pointed by the
                // left pointer is no longer a part of the window
                windowCounts[c]--;

                if(dicT.find(c)!=dicT.end() && windowCounts[c]<dicT[c])
                {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a
                // new window
                l++;
            }
            // Keep expanding the window once we are done contracting
            r++;
        }
        return ans[0]==-1?"":s.substr(ans[1],ans[2]-ans[1]+1);
    }
};