    int findMaximumXOR(vector<int>& nums) {

       int i,j;
       int n=nums.size();

       int ans=0;
       for(i=0;i<n;i++)
       {

          for(j=i;j<n;j++)
          {
            ans=max(ans,nums[i]^nums[j]);
          }

       }

       return ans;
    }

/////////////////////------------------/////////////////////////
struct Node{

   Node* child[2];

   Node(){

     for(int i=0;i<2;i++)
     {
        child[i]=nullptr;
     }

   }

};

class Trie
{
  private:
  Node* root;
  public:
    Trie()
    {
      root=new Node;
    }
  void insert(int n)
  {
    Node* curr=root;

    int mask=31;

    while(mask>=0)
    {
        int sb=(n>>mask)&1;

        if(curr->child[sb]==nullptr)
        {
            curr->child[sb]=new Node;
        }

        curr=curr->child[sb];

        mask-=1;

    }


  }

  int max_xor_with_others(int num)
  {
     // start from the root node
     Node* node=root;

     // Initialize the maximum XOR value
     int maxNum=0;

     // Iterate through each bit of
     // the number (from left to right )

     for(int i=31;i>=0;i--)
     {


     // Extract the i-th
     // bit of the number

     int bit=(num>>i)&1;

     // If the complement of the current
     // bit exist in the Trie

     if(node->child[1-bit])
     {

     // Update the maximum XOR
     // value with the current bit

     maxNum |=(1<<i);

     // Move to the child node corresponding
     // to the complement of the current bit

     node=node->child[1-bit];

     }
     else
     {
        // Move to the child node
        // corresonding to the current bit
        node=node->child[bit];
     }



     }

     return maxNum;

  }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie obj;

        // time complexity 32*nums.size()
        for(auto v:nums)
        {
            obj.insert(v);
        }

        int ans=0;
        // time complexity 32*nums.size()
        for(auto v:nums)
        {
            ans=max(ans,obj.max_xor_with_others(v));
        }

        return ans;

    }
};