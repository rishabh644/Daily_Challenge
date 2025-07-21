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

    int dfs(TreeNode* root,vector<vector<int>>&ht)
    {
        if(root==NULL)
        return 0;

        if(root->left==NULL && root->right==NULL)
        {

           if(ht.size()==0)
           {
            ht.push_back({root->val});
           }
           else
           {
            ht[0].push_back({root->val});
           }
           return 1;
        }

        int lh=dfs(root->left,ht);
        int rh=dfs(root->right,ht);

        int dh=max(lh,rh);

        if(ht.size()==dh)
        {
            ht.push_back({root->val});
        }
        else
        {
            ht[dh].push_back({root->val});
        }

        return 1+dh;

    }

    vector<vector<int>> findLeaves(TreeNode* root)
    {

      vector<vector<int>>ans;
      dfs(root,ans);

      return ans;


    }
};
/////////////////////////////////////////////
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
   vector<vector<int>>solution;
public:
    int getHeight(TreeNode *root)
    {
        if(!root)
        return -1;

        //first calculate the height of the left and right children
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);

        // based on the height of the left and right children, obtain the height of the current (parent) node

        int currHeight=max(leftHeight,rightHeight)+1;

        if(this->solution.size()==currHeight)
        {
            this->solution.push_back({});
        }
        // insert the value at the corrent position in the solution array

        this->solution[currHeight].push_back(root->val);

        // return the height of the current node
        return currHeight;
    }

    vector<vector<int>> findLeaves(TreeNode* root)
    {
       this->solution.clear();
       getHeight(root);
       return this->solution;

    }
};