class Solution {
public:
    string mergeAlternately(string w1, string w2)
    {

       bool odd=true;

       int i=0,j=0;

       int m=w1.size();
       int n=w2.size();

       string ans="";

       while(i<m && j<n)
       {

          if(odd)
          ans+=w1[i++];
          else
          ans+=w2[j++];

          odd=!odd;


       }

       while(i<m)
       ans+=w1[i++];
       while(j<n)
       ans+=w2[j++];

       return ans;

    }
};