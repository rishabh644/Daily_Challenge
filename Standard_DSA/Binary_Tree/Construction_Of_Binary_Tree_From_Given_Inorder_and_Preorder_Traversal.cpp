TreeNode* mybuildTree(vector<int>& preorder,vector<int>& inorder,int i,int j,int m,int n)
    {
      if(i>j || m>n)
      return NULL;

      int root_val=preorder[i];

      TreeNode* root=new TreeNode(root_val);
      int mid;
      for(int k=m;k<=n;k++)
      {
          if(inorder[k]==root_val)
          mid=k;
      }

      int num_of_el=mid-m;

      root->left=mybuildTree(preorder,inorder,i+1,i+num_of_el, m, mid-1);
      root->right=mybuildTree(preorder,inorder,i+num_of_el+1,j,mid+1,n);

      return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

     return mybuildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

    }