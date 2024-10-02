
struct Node{

    Node* arr[26];
    bool isword;
    Node()
    {

     for(int i=0;i<26;i++)
     {
          arr[i]=NULL;
     }

     isword=false;

    }

};

class Trie{
   public:
   Node* root=new Node;
   void insert(string word)
   {
       int n=word.size();
       Node* cr=root;
       for(int i=0;i<n;i++)
       {
           int indx=word[i]-'a';
           if(cr->arr[indx]==NULL)
           {
            cr->arr[indx]=new Node;
           }

           cr=cr->arr[indx];
       }

       cr->isword=true;

   }

   bool search(string word)
   {
      int n=word.size();
      Node* cr=root;
      for(int i=0;i<n;i++)
      {
         int indx=word[i]-'a';
         if(cr->arr[indx]==NULL)
         {
            return false;
         }
         cr=cr->arr[indx];
      }

      return cr->isword;

   }

   bool startswith(string prefix)
   {
      int n=prefix.size();
      Node* cr=root;
      for(int i=0;i<n;i++)
      {
          int indx=prefix[i]-'a';
          if(cr->arr[indx]==NULL)
          {
            return false;
          }
          cr=cr->arr[indx];
      }

      return true;
   }

   bool query(string word)
   {

       int ans=0;
       Node* cr=root;
       int n=word.size();
       int i=0;
       for(i=0;i<n;i++)
       {
          int indx=word[i]-'a';
          if(cr->arr[indx]==NULL)
          {
            break;
          }
          cr=cr->arr[indx];
       }

       return i;

   }

};

class Solution {
public:
    int solve(int ind,string& target,Trie& obj,vector<int>&dp)
    {
       int n=target.size();
       if(ind==n)
       return 0;

       if(dp[ind]!=-1)
       return dp[ind];

       int ans=n+1;

       Node* rt=obj.root;
       int i=ind;
       while(i<n)
       {
            int indx=target[i]-'a';
            if(rt->arr[indx]==NULL)
            break;
            else
            {
                rt=rt->arr[indx];
                ans=min(ans,1+solve(i+1,target,obj,dp));
            }
            i+=1;
       }


       dp[ind]=ans;

       return dp[ind];

    }
    int minValidStrings(vector<string>& words, string target)
    {

        Trie obj;

        for(string s :words)
        {
            obj.insert(s);
        }

        int n=target.size();

        vector<int>dp(n,-1);

        int val=solve(0,target,obj,dp);

        if(val>n)
        {
            return -1;
        }

        return val;

    }

};

-------------------------------Bottom UP DP---------------------------------------------
struct Node
{

    Node* arr[26];
    bool isword;
    Node()
    {

     for(int i=0;i<26;i++)
     {
          arr[i]=NULL;
     }

     isword=false;

    }

};

class Trie{
   public:
   Node* root=new Node;
   void insert(string word)
   {
       int n=word.size();
       Node* cr=root;
       for(int i=0;i<n;i++)
       {
           int indx=word[i]-'a';
           if(cr->arr[indx]==NULL)
           {
            cr->arr[indx]=new Node;
           }

           cr=cr->arr[indx];
       }

       cr->isword=true;

   }

   bool search(string word)
   {
      int n=word.size();
      Node* cr=root;
      for(int i=0;i<n;i++)
      {
         int indx=word[i]-'a';
         if(cr->arr[indx]==NULL)
         {
            return false;
         }
         cr=cr->arr[indx];
      }

      return cr->isword;

   }

   bool startswith(string prefix)
   {
      int n=prefix.size();
      Node* cr=root;
      for(int i=0;i<n;i++)
      {
          int indx=prefix[i]-'a';
          if(cr->arr[indx]==NULL)
          {
            return false;
          }
          cr=cr->arr[indx];
      }

      return true;
   }

   bool query(string word)
   {

       int ans=0;
       Node* cr=root;
       int n=word.size();
       int i=0;
       for(i=0;i<n;i++)
       {
          int indx=word[i]-'a';
          if(cr->arr[indx]==NULL)
          {
            break;
          }
          cr=cr->arr[indx];
       }

       return i;

   }

};

class Solution {
public:
    int solve(int ind,string& target,Trie& obj,vector<int>&dp)
    {
       int n=target.size();
       if(ind==n)
       return 0;

       if(dp[ind]!=-1)
       return dp[ind];

       int ans=n+1;

       Node* rt=obj.root;
       int i=ind;
       while(i<n)
       {
            int indx=target[i]-'a';
            if(rt->arr[indx]==NULL)
            break;
            else
            {
                rt=rt->arr[indx];
                ans=min(ans,1+solve(i+1,target,obj,dp));
            }
            i+=1;
       }


       dp[ind]=ans;

       return dp[ind];

    }
    int minValidStrings(vector<string>& words, string target)
    {

        Trie obj;

        for(string s :words)
        {
            obj.insert(s);
        }

        int n=target.size();

        vector<int>dp(n+1,n+1); //Initialize dp with a large value

        dp[n]=0; // Base case: when the target string is fully matched

        // Iterate over target string in reverse

        for(int i=n-1;i>=0;--i)
        {
            Node* rt=obj.root;

            int j=i;

            // Try to extend the substring starting from 'i' as much as  possible

            while(j<n)
            {
                int indx=target[j]-'a';

                if(rt->arr[indx]==NULL)
                break; // No valid word can be formed

                rt=rt->arr[indx];

                // If we find a valid word, update the dp table

                dp[i]=min(dp[i],1+dp[j+1]);

                j++;

            }

        }

        // If dp[0] is greater than the size of the target, it means we //couldn't form the string

        return dp[0]>n?-1:dp[0];

    }

};