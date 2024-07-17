vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {


        int sz=queries.size();
        int n=nums.size();

        vector<int>ans(sz,-1);


        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=queries[i][1])
                {


                    ans[i]=max(ans[i],queries[i][0]^nums[j]);


                }
            }
        }

        return ans;
}
};
///////////////////----------------///////////////////
// Using Trie

struct Node{

    Node* child[2];

    Node()
    {
        for(int i=0;i<2;i++)
        {
            child[i]=nullptr;
        }
    }
};

class Trie{
 private:
 Node* root;

 public:
    Trie(){
        root=new Node;
    }
    void insert(int n)
    {
        Node* curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(curr->child[bit]==nullptr)
            {
                curr->child[bit]=new Node;
            }
            curr=curr->child[bit];
        }

    }

    int getmax(int x)
    {
        Node* curr=root;
        int max=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i)&1;

            if(curr->child[1-bit]!=nullptr)
            {
                max=max|(1<<i);
                curr=curr->child[1-bit];
            }
            else
            {
                curr=curr->child[bit];
            }

        }

        return max;

    }
};


class Solution {

public:
    static bool mycmp(vector<int>&a,vector<int>&b)
    {
       return a[1]<b[1];
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
    {


               sort(nums.begin(),nums.end());
              // sort(queries.begin(),queries.end(),mycmp);


               Trie obj;

               int qsz=queries.size();
               int n=nums.size();
               int j=0;
               vector<int>ans(qsz);
               vector<vector<int>>Queries;

               for(int i=0;i<qsz;i++)
               {
                Queries.push_back({queries[i][0],queries[i][1],i});
               }

               sort(Queries.begin(),Queries.end(),mycmp);

               for(int i=0;i<qsz;i++)
               {



                  int mxe=Queries[i][1];
                  int ind=Queries[i][2];
                  if(nums[0]>mxe)
                  {
                    ans[ind]=-1;
                    continue;
                  }

                  while(j<n && nums[j]<=mxe)
                  {

                    obj.insert(nums[j]);
                    j+=1;

                  }

                  ans[ind]=obj.getmax(Queries[i][0]);


               }

               return ans;

    }
};