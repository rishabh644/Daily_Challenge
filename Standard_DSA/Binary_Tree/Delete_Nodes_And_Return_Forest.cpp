
TreeNode* postorder_traversal(TreeNode* root,bool haveParent,vector<TreeNode*>ans,unordered_set<int>&ust)
{
   if(root==nullptr)
       return root;

   root->left = postorder_traversal(root->left, true, ans, ust);
   root->right = postorder_traversal(root->right, true, ans, ust);

   if(ust.find(root->val)!=ust.end())
   {
      if(root->left!=NULL)
          ans.push_back(root->left);
      if(root->right!=NULL)
          ans.push_back(root->right);

      delete (root);

      return NULL;
   }

   if(!haveParent)
       ans.push_back(root);
   return root;
}

vector<TreeNode*> delNodes(TreeNode* root,vector<int>& to_delete)
{
    unordered_set<int> ust(to_delete.begin(), to_delete.end());

    vector<TreeNode *> ans;

    bool haveParent = false;

    postorder_traversal(root, haveParent, ans, ust);
}

//////////////////
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
    TreeNode* postorder_traversal(TreeNode* root,vector<TreeNode*>&forest,unordered_set<int>&ust)
    {
       if(root==nullptr)
       return root;
       root->left=postorder_traversal(root->left,forest,ust);
       root->right=postorder_traversal(root->right,forest,ust);
       if(ust.find(root->val)!=ust.end())
       {
          if(root->left!=nullptr)
          forest.push_back(root->left);
          if(root->right!=nullptr)
          forest.push_back(root->right);
          delete(root);
          return nullptr;
       }

       return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      unordered_set<int>ust(to_delete.begin(),to_delete.end());
      vector<TreeNode*>forest;
      bool haveParent=false;
      root=postorder_traversal(root,forest,ust);

      if(root!=nullptr)
      forest.push_back(root);

      return forest;

    }
};
////////////