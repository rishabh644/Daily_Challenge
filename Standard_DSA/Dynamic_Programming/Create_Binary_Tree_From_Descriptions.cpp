    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int,TreeNode* >ump;
        unordered_map<int,bool>isChild;



        for(auto ds:descriptions)
        {
              int pv=ds[0];
              int cv=ds[1];
              int isLeft=ds[2];

              if(ump.find(pv)==ump.end())
              {
                ump[pv]=new TreeNode(pv);
              }
              if(ump.find(cv)==ump.end())
              {
                ump[cv]=new TreeNode(cv);
              }

               if (isLeft == 1) {
            ump[pv]->left = ump[cv];
            } else {
            ump[pv]->right = ump[cv];
             }

             isChild[cv]=true;
             if (isChild.find(pv) == isChild.end()) {
              isChild[pv] = false;}
        }






        TreeNode* root=nullptr;

        for(const auto& it:isChild)
        {
            if(it.second==false)
            {
                root=ump[it.first];
                break;
            }
        }

        return root;

    }