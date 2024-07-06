    vector<int> topView(Node *root)
    {
        //Your code here


        if(root==NULL)
        return {};

        vector<int>ans;
        map<int,int>omp;
        pair<Node *,int>pr;
        Node* node;
        int dis=0;

        queue<pair<Node*,int>>qu;

        qu.push({root,0});


        while(!qu.empty())
        {

            pr=qu.front();

            node=pr.first;
            dis=pr.second;

            qu.pop();

            if(omp[dis]==0)
            {
                omp[dis]=node->data;
            }
            if(node->left!=NULL)
            {
                qu.push({node->left,dis-1});
            }
            if(node->right!=NULL)
            {
                qu.push({node->right,dis+1});
            }

        }


        for(auto itr=omp.begin();itr!=omp.end();itr++)
        {
            ans.push_back(itr->second);
        }

        return ans;
    }