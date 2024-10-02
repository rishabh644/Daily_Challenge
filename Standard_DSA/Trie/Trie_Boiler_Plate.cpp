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
