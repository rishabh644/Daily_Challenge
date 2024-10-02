/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleBST(
    int start,int end,map<pair<int,int>,vector<TreeNode*>>&memo)
    {
        vector<TreeNode*>res;

        if(start>end)
        {
            res.push_back(nullptr);
            return res;
        }

        if(memo.find(make_pair(start,end))!=memo.end())
        {
            return memo[make_pair(start,end)];
        }

        // Iterate through all values from start to end to
        // construct left and right subtress recursively

        for(int i=start;i<=end;++i)
        {
           vector<TreeNode*>leftSubTrees=allPossibleBST(start,i-1,memo);
           vector<TreeNode*>rightSubTrees=allPossibleBST(i+1,end,memo);

           // Loop through all left and right subtrees and connect
           // them to the ith root

           for(auto left:leftSubTrees)
           {

             for(auto right:rightSubTrees)
             {
                TreeNode* root=new TreeNode(i,left,right);
                res.push_back(root);
             }

           }


        }


        return memo[make_pair(start,end)]=res;

    }

    vector<TreeNode*> generateTrees(int n)
    {

      map<pair<int,int>,vector<TreeNode*>>memo;
      return allPossibleBST(1,n,memo);

      // O(4^n/n^1.5)

    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<TreeNode*> generateTrees(int n)
    {

     vector<vector<vector<TreeNode*>>>dp(n+1,vector(n+1,vector<TreeNode*>(0)));

     for(int i=1;i<=n;i++)
     {
        dp[i][i].push_back(new TreeNode(i));
     }

     for(int numberOfNodes=2;numberOfNodes<=n;numberOfNodes++)
     {
        for(int start=1;start<=n-numberOfNodes+1;start++)
        {
            int end=start+numberOfNodes-1;

            for(int i=start;i<=end;i++)
            {
                vector<TreeNode*> leftSubtrees=i-1>=start?dp[start][i-1]:vector<TreeNode*>({NULL});

                vector<TreeNode*> rightSubtrees=i+1<=end?dp[i+1][end]:vector<TreeNode*>({NULL});

                for(auto left:leftSubtrees)
                {
                    for(auto right:rightSubtrees)
                    {
                        TreeNode* root=new TreeNode(i,left,right);
                        dp[start][end].push_back(root);
                    }
                }


            }


        }
     }

     return dp[1][n];

    }
/////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
       vector<vector<TreeNode*>>dp(n+1);
       dp[0].push_back(NULL);
       for(int numberOfNodes=1;numberOfNodes<=n;numberOfNodes++)
       {
        for(int i=1;i<=numberOfNodes;i++)
        {
            int j=numberOfNodes-i;
            for(auto left:dp[i-1])
            {
                for(auto right:dp[j])
                {
                    TreeNode* root=new TreeNode(i,left,clone(right,i));
                    dp[numberOfNodes].push_back(root);
                }
            }
        }
       }
       return dp[n];
    }

    private :
    TreeNode* clone(TreeNode* node,int offset)
    {
         if(node==NULL)
         {
            return NULL;
         }
         TreeNode* cloneNode=new TreeNode(node->val+offset);
         cloneNode->left=clone(node->left,offset);
         cloneNode->right=clone(node->right,offset);
         return cloneNode;
    }

};