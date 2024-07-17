int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    unordered_set<string>ump;
    int ans=2;
    int n=s.size();
    for(int len=1;len<=(n-1);len++)
    {
        int i=0;
        int j=i+len-1;
        while(j<n)
        {
            string ss=s.substr(i,j-i+1);

            if (ump.find(ss) == ump.end())
            {
              ans += 1;
              ump.insert(ss);
            }

            i+=1;
            j+=1;
        }
    }

    return ans;

}

////////////////////----------------//////////////////


struct Node {

   Node* links[26];

   bool containsKey(char ch){
       return links[ch-'a'];
   }

   void put(char ch,Node* node)
   {
       links[ch-'a']=node;
   }

   Node* get(char ch){
         return links[ch-'a'];
   }


};

int countDistinctSubstrings(string &word)
{
    //    Write your code here.

    int cnt=0;
    Node* root=new Node;

    for(int i=0;i<word.size();i++){
        Node* node=root;
        for(int j=i;j<word.size();j++)
        {
            if(!node->containsKey(word[j]))
            {
                  cnt+=1;
                  node->put(word[j],new Node);
            }
            node=node->get(word[j]);

        }
    }

    return cnt+1;

}

//////////////////////-------------------/////////////////////////
