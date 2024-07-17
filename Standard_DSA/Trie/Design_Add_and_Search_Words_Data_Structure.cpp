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

class WordDictionary {
private:
    trie* root;
public:
    WordDictionary() {
        root=new trie;
    }

    void addWord(string word) {
        trie* curr=root;

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
        return my_search(curr,word,0);
    }

private:
    bool my_search(trie* curr,const string& word,int i)
    {
        if(i==word.size())
        return curr->isEnd;
        if(word[i]=='.')
        {

        for(int j=0;j<26;j++)
        {
           if(curr->arr[j]!=NULL)
           {
             if(my_search(curr->arr[j],word,i+1))
             return true;
           }


        }

        return false;

        }
        else if(curr->arr[word[i]-'a']==NULL)
        return false;

        return my_search(curr->arr[word[i]-'a'],word,i+1);


    }

};