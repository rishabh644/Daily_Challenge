class Solution {


public:

    bool myisValid(TreeNode* root,long long m,long long mx)
    {
        if(root==NULL)
        return true;

        return root->val>m && root->val<mx && myisValid(root->left,m,root->val) && myisValid(root->right,root->val,mx);

    }

    bool isValidBST(TreeNode* root) {

        return myisValid(root,INT_MIN-(1*1ll),INT_MAX+(1*1ll));
    }
};