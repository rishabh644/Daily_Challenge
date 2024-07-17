struct trie{

   bool isEnd;

   trie* arr[26];

   trie()
   {
       isEnd=false;

       for(int i=0;i<26;i++)
       arr[i]=nullptr;
   }


};

class Trie{

   private:
   trie* root;
   public:
   Trie()
   {
       root=new trie;
   }

   void insert(string& word)
   {
       trie* curr=root;

       for(auto ch:word)
       {
           if(curr->arr[ch-'a']==nullptr)
           curr->arr[ch-'a']=new trie;

           curr=curr->arr[ch-'a'];
       }
       curr->isEnd=true;
   }

   int check_obj(string& s)
   {

     int n=s.size();
     trie* curr=root;
     int i=0;
     while(i<n)
     {
         curr=curr->arr[s[i]-'a'];

         if(curr->isEnd==false)
         return 0;

         i+=1;
     }

     return n;
   }

};


string completeString(int n, vector<string> &a){
    // Write your code here.

    sort(a.begin(),a.end());

    Trie obj;
    for(auto s:a)
    obj.insert(s);

    int mxl=0;
    string ans="None";


    for(auto s:a)
    {  int l=obj.check_obj(s);
       if(l>mxl)
       {
           mxl=l;
           ans=s;
       }
    }

    return ans;

}