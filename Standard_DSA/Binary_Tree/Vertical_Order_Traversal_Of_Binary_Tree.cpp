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
private:
     map<int,vector<int>>mp;
public:
    void bfs(TreeNode* root,int d)
    {

       queue<pair<TreeNode*,int>>qu;

       pair<TreeNode*,int>pr;

       qu.push({root,d});

       while(!qu.empty())
       {
           pr=qu.front();
           qu.pop();

           root=pr.first;
           d=pr.second;

           mp[d].push_back(root->val);

           if(root->left!=NULL)
           qu.push({root->left,d-1});
           if(root->right!=NULL)
           qu.push({root->right,d+1});

       }


    }


    vector<vector<int>> verticalOrder(TreeNode* root)
    {

        if(root==NULL)
        return {};


       bfs(root,0);

       vector<vector<int>>ans;

       for(auto it=mp.begin();it!=mp.end();it++)
       {
        ans.push_back(it->second);
       }

       return ans;
    }
};