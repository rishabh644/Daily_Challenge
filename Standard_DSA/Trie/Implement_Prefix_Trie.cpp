struct trie{

    bool isEnd;

    trie* arr[26];

    trie()
    {
        isEnd=false;

        for(int i=0;i<26;i++)
        {
            arr[i]=NULL;
        }
    }


};

class Trie {
private:
   trie *root;
public:
    Trie() {
        root=new trie;
    }

    void insert(string word) {
        trie *curr=root;
        int i=0;
        int n=word.size();
        while(i<n)
        {
            if(curr->arr[word[i]-'a']!=NULL)
            {
                curr=curr->arr[word[i]-'a'];
            }
            else
            {
                trie* temp=new trie;
                curr->arr[word[i]-'a']=temp;
                curr=temp;
            }
            i+=1;
        }

        curr->isEnd=true;

    }

    bool search(string word) {

        trie* curr=root;

        int i=0;
        int n=word.size();
        while(i<n)
        {
            if(curr->arr[word[i]-'a']==NULL)
            break;

            curr=curr->arr[word[i]-'a'];
            i+=1;
        }

        return (i==n && curr->isEnd)?true:false;


    }

    bool startsWith(string prefix) {

         trie* curr=root;

         int i=0;
         int n=prefix.size();

         while(i<n)
         {
            if(curr->arr[prefix[i]-'a']==NULL)
            break;

            curr=curr->arr[prefix[i]-'a'];
            i+=1;
         }
         if(i==n)
         return true;
         else
         return false;

    }
};
////////////////
struct trie{

    bool isEnd;

    trie* arr[26];

    trie()
    {
        isEnd=false;

        for(int i=0;i<26;i++)
        {
            arr[i]=NULL;
        }
    }


};

class Trie {
private:
   trie *root;
public:
    Trie() {
        root=new trie;
    }

    void insert(string word) {
        trie *curr=root;

        for(auto ch:word)
        {
            if(curr->arr[ch-'a']==NULL)
            curr->arr[ch-'a']=new trie;

            curr=curr->arr[ch-'a'];
        }


        curr->isEnd=true;

    }

    bool search(string word) {

        trie* curr=root;

        for(auto ch:word)
        {
            if(curr->arr[ch-'a']==NULL)
            return false;

            curr=curr->arr[ch-'a'];
        }

        return curr->isEnd;


    }

    bool startsWith(string prefix) {

         trie* curr=root;

         for(auto ch:prefix)
         {
            if(curr->arr[ch-'a']==NULL)
            return false;

            curr=curr->arr[ch-'a'];
         }

         return true;

    }
};
// Less line