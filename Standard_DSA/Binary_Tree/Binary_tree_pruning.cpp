class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {

        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==1)
        {   TreeNode* lft=pruneTree(root->left);
            TreeNode* rght=pruneTree(root->right);
            root->left=lft;
            root->right=rght;
            return root;
        }
        else
        {
            TreeNode* lft=pruneTree(root->left);
            TreeNode* rght=pruneTree(root->right);

            if(lft==NULL && rght==NULL)
            {
                return NULL;
            }
            else
            {
                root->left=lft;
                root->right=rght;
                return root;
            }

        }

    }
};