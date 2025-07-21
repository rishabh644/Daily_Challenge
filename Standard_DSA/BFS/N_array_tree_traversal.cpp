/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {

        if(root==NULL)
        return {};

        vector<vector<int>>ans;

        queue<Node*>qu;

        qu.push(root);



        Node* nd;

        while(!qu.empty())
        {

            int sz=qu.size();
            vector<int>temp;

            while(sz--)
            {
                nd=qu.front();
                qu.pop();

                int csz=nd->children.size();

                for(int k=0;k<csz;k++)
                {
                    qu.push(nd->children[k]);
                }

                temp.push_back(nd->val);
            }

            ans.push_back(temp);
        }


        return ans;


    }
};