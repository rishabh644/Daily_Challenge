class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
         int countarr[26]={0};

         for(char ch:magazine)
         {
            countarr[ch-'a'] +=1;
         }

         for(char ch:ransomNote)
         {

            countarr[ch-'a'] -=1;

            if(countarr[ch-'a']<0)
            return false;

         }

         return true;


    }
};