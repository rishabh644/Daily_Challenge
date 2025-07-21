class Solution {
public:
    void bfs(TreeNode* root,int dis,map<int,vector<int>>&mp)
    {

        if(root==NULL)
        return;

        queue<pair<int,TreeNode*>>qu;

        qu.push({dis,root});

        pair<int,TreeNode*>pr;

        while(!qu.empty())
        {
            map<int,vector<int>>tmp;
            int sz=qu.size();

            while(sz-->0)
            {
                pr=qu.front();
                qu.pop();
                int dis=pr.first;
                TreeNode* Node=pr.second;
                tmp[dis].push_back(Node->val);

                if(Node->left!=NULL)
                qu.push({dis-1,Node->left});
                if(Node->right!=NULL)
                qu.push({dis+1,Node->right});
            }

            for(auto it=tmp.begin();it!=tmp.end();it++)
           {

           vector<int>temp=it->second;
           sort(temp.begin(),temp.end());

           for(auto vl:temp)
           {
            mp[it->first].push_back(vl);
           }

           }


        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {


        map<int,vector<int>>mp;

        bfs(root,0,mp);

        vector<vector<int>>ans;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
           vector<int>temp=it->second;
           ans.push_back(temp);
        }

        return ans;

    }
};