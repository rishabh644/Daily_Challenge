class Solution {
public:
    unordered_map<string,int>wordCount;
    int wordLength;
    int substringSize;
    int k;

    bool check(int i,string s)
    {

      // Copy the original dictionary to use for this index
      unordered_map<string,int>remaining=wordCount;
      int wordsUsed=0;

      //Each iteration will check for a match in words

      for(int j=i;j<i+substringSize;j+=wordLength)
      {

        string sub=s.substr(j,wordLength);

        if(remaining[sub]!=0)
        {
            remaining[sub]--;
            wordsUsed++;
        }
        else
        {
            break;
        }

      }


      return wordsUsed==k;

    }


    vector<int> findSubstring(string s, vector<string>& words)
    {
         int n=s.size();
         k=words.size();
         wordLength=words[0].size();
         substringSize=wordLength*k;

         for(string word:words)
         {
            if(wordCount.find(word)==wordCount.end())
            {
                wordCount[word]=1;
            }
            else
            {
                wordCount[word]+=1;
            }
         }

         vector<int>ans;

         for(int i=0;i<n-substringSize+1;i++)
         {

            if(check(i,s))
            {
                ans.push_back(i);
            }

         }

          return ans;


    }
};

///////////
// time complexity is O((n-a.b).a.b)
   // space complexity is O(a+b)


class Solution {
public:
    unordered_map<string,int>wordCount;
    int n;
    int wordLength;
    int substringSize;
    int k;

    void slidingWindow(int left,string &s,vector<int>&ans)
    {
        unordered_map<string,int>wordsFound;
        int wordsUsed=0;
        bool excessWord=false;

        for(int right=left;right<=n-wordLength;right+=wordLength)
        {
            string sub=s.substr(right,wordLength);

            if(!wordCount.count(sub))
            {
                // Mismatched word-rest the window
                wordsFound.clear();
                wordsUsed=0;
                excessWord=false;
                left=right+wordLength;
            }
            else
            {
                //If we reached max window size or have an excess word
               while(right-left==substringSize || excessWord)
               {

                string leftmostWord=s.substr(left,wordLength);
                left+=wordLength;
                wordsFound[leftmostWord]--;
                if(wordsFound[leftmostWord]>=wordCount[leftmostWord]){
                    excessWord=false;
                }
                else
                {
                    wordsUsed--;
                }



               }
               // Keep track of how many times this word occurs //in the window
               wordsFound[sub]++;

               if(wordsFound[sub]<=wordCount[sub])
               {
                wordsUsed++;
               }
               else
               {
                excessWord=true;
               }

               if(wordsUsed==k && !excessWord)
               {
                 ans.push_back(left);
               }

            }

        }


    }



    vector<int> findSubstring(string s, vector<string>& words)
    {
            n=s.length();
            k=words.size();
            wordLength=words[0].length();
            substringSize=wordLength*k;

            for(string &word:words)
            {
                wordCount[word]++;
            }

            vector<int>ans;

            for(int i=0;i<wordLength;i++)
            {
                slidingWindow(i,s,ans);
            }

            return ans;
    }
};
// O(a+n.b)