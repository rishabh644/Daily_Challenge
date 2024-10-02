#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool mycount(string& word,vector<vector<int>>&vc,int i )
    {   if(i==0){
         if(word[i]=='a')
         {
            vc[i][0]+=1;
            return true;
         }
         else if(word[i]=='e')
         {
            vc[i][1]+=1;
            return true;
         }
         else if(word[i]=='i')
         {
            vc[i][2]+=1;
            return true;
         }
         else if(word[i]=='o')
         {
            vc[i][3]+=1;
            return true;
         }
         else if(word[i]=='u')
         {
            vc[i][4]+=1;
            return true;
         }
         else
         {
            return false;
         }
         }
         else
         {
          for(int k=0;k<5;k++)
                 {
                     vc[i][k] = vc[i - 1][k];
                 }

           if(word[i]=='a')
         {
            vc[i][0]+=1;
            return true;
         }
         else if(word[i]=='e')
         {
            vc[i][1]+=1;
            return true;
         }
         else if(word[i]=='i')
         {
            vc[i][2]+=1;
            return true;
         }
         else if(word[i]=='o')
         {
            vc[i][3]+=1;
            return true;
         }
         else if(word[i]=='u')
         {
            vc[i][4]+=1;
            return true;
         }

         else
         {
            return false;
         }

         }

    }

    int countOfSubstrings(string word, int k)
    {



        vector<vector<int>>vc(word.size(),vector<int>(5,0));
        vector<int>cc(word.size(),0);


        if(!mycount(word,vc,0))
        {
            cc[0]=1;
        }

        for(int i=1;i<word.size();i++)
        {

            cc[i] = cc[i - 1];

            if(!mycount(word, vc, i))
                cc[i] = 1 + cc[i];
        }


            int ans = 0;
        int vcn,ccn;
        for(int i=0;i<=(word.size()-(5+k));i++)
        {
            int j=i+(5+k-1);
            while(j<word.size())
            {

                if(i==0)
                {
                 if(cc[j]>k)
                 break;

                 bool alv=true;
                 for(int k=0;k<5;k++)
                 {
                    if(vc[j][k]<=0)
                    {
                        alv=false;
                        break;
                    }
                 }

                 if(alv && cc[j]==k)
                 {
                    ans+=1;
                 }


                }
                else
                {
                   int ccn=cc[j]-cc[i-1];
                   if(ccn>k)
                   break;

                   bool alv=true;

                   for(int k=0;k<5;k++)
                   {
                    if((vc[j][k]-vc[i-1][k])<=0)
                    {
                        alv=false;
                        break;
                    }
                   }
                   if(alv && ccn==k)
                   {
                    ans+=1;
                   }

                }

                j++;
            }

        }

        return ans;


    }
};

int main()
{

    Solution obj;

    string st = "ieaouqqieaouqq";
    int k = 1;
    cout << "execution " << endl;
    cout << obj.countOfSubstrings(st, k) << endl;

    return 0;
}
///

 class Solution {
public:


    int countOfSubstrings(string word, int k)
    {

      int n=word.length();

      vector<char>vowels={'a','e','i','o','u'};

      int ans=0;

      for(int i=0;i<n;i++)
      {
         vector<int>freq(26,0);
         int cnt=0;

         for(int j=i;j<n;j++)
         {
            freq[word[j]-'a']++;
            bool isVowel=false;

            for(int l=0;l<5;l++)
            {
                if(word[j]==vowels[l])
                isVowel=true;
            }

            if(!isVowel)
            cnt++;

            bool containsAllVowels=true;

            if(freq['a'-'a']==0)
            containsAllVowels=false;
            if(freq['e'-'a']==0)
            containsAllVowels=false;
            if(freq['i'-'a']==0)
            containsAllVowels=false;
            if(freq['o'-'a']==0)
             containsAllVowels=false;
             if(freq['u'-'a']==0)
             containsAllVowels=false;

            if(containsAllVowels && cnt==k)
            ans++;

         }
      }

      return ans;

    }
};