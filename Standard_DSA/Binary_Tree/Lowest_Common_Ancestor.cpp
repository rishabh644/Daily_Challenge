    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         if(root==NULL)
         return NULL;

         if(root==p || root==q)
         return root;


         TreeNode* leftc=lowestCommonAncestor(root->left,p,q);
         TreeNode* rightc=lowestCommonAncestor(root->right,p,q);


         if(leftc!=NULL && rightc!=NULL)
         return root;
         else if(leftc!=NULL)
         return leftc;
         else
         return rightc;

    }