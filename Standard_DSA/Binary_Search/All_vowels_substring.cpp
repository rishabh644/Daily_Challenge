class Solution {
public:
    int countVowelSubstrings(string w)
    {

       int n=w.size();
       int cnt=0;

       auto checkAllVowels=[&](vector<int>freq){


        for(int k=0;k<26;k++)
        {
            if( (k==0 || k==4 || k==8 || k==14 || k==20) )
            {
                if(freq[k]==0)
                return false;
            }
            else if(freq[k]!=0)
            {
                return false;
            }


        }

        return true;

                          };
       for(int i=0;i<n;i++)
       {
          vector<int>freq(26,0);
          for(int j=i;j<n;j++)
          {
             freq[w[j]-'a']++;
             if(checkAllVowels(freq))
             {
                cnt+=1;
             }

          }
       }
       return cnt;
    }
};
/////////////////---------------------////////////////////
const int N=101;

int pre[N+1][26];

class Solution {
public:
    int countVowelSubstrings(string w)
    {

       int n=w.size();
       int ans=0;
       auto idx=[](char ch){
        return ch-'a';
       };

       for(int k=0;k<26;k++)
       pre[0][k]=0;

       for(int i=0;i<n;i++)
       {
         int ind=idx(w[i]);
         for (int k = 0; k < 26; k++) {
                pre[i + 1][k] = pre[i][k];  // Copy the previous frequencies
            }
         pre[i+1][ind]+=1;
       }
        auto checkAllVowelPresent=[&](int l,int r)
         {
            for(int k=0;k<26;k++)
            {
                if(k==0 || k==4 || k==8 || k==14 || k==20)
                {
                    if((pre[r+1][k]-pre[l][k])==0)
                    return false;
                }
                else if((pre[r+1][k]-pre[l][k])!=0)
                {
                    return false;
                }
            }

            return true;

         };


       // Count all valid vowel substrings
        for (int i = 0; i < n; i++) {
            if (w[i] != 'a' && w[i] != 'e' && w[i] != 'i' && w[i] != 'o' && w[i] != 'u') {
                continue; // Skip non-vowel starting points
            }
            for (int j = i; j < n; j++) {
                if (w[j] != 'a' && w[j] != 'e' && w[j] != 'i' && w[j] != 'o' && w[j] != 'u') {
                    break; // Stop if we encounter a non-vowel
                }
                if (checkAllVowelPresent(i, j)) {
                    ans++;
                }
            }
        }

       return ans;
    }
};
/////////////////////////////--------------------------/////////////////////////////////
const int N=101;

int pre[N+1][26];

class Solution {
public:
    int countVowelSubstrings(string w)
    {

       int vow=0,cnt=0,m[123]={};

       string vowels("aeiou");

       for(int i=0,j=0,k=0;i<w.size();++i)
       {
          if(vowels.find(w[i])!=string::npos)
          {
             vow+=++m[w[i]]==1;

             for(;vow==5;++k)
                vow-=--m[w[k]]==0;
             cnt+=k-j;
          }
          else
          {
              m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;
              j = k = i + 1;
          }

       }

       return cnt;

    }
};