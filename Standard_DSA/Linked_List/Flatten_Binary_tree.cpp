   TreeNode* myFlatten(TreeNode* prev,TreeNode* curr)
    {
        if(curr==NULL)
        return prev;

        prev->right=curr;

        TreeNode* next=curr->right;

        TreeNode* tail=myFlatten(curr,curr->left);

        curr->left=NULL;

        return myFlatten(tail,next);


    }
    void flatten(TreeNode* root)
    {

        if(root==NULL)
        return;

        TreeNode* prev=new TreeNode(root->val,NULL,root);

        myFlatten(prev,root);

        root=prev->right;
    }