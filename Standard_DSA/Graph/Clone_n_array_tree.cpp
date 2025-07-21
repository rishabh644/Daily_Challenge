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
    Node* cloneTree(Node* root)
    {
        if(root==NULL)
        return root;

        queue<Node*>qu;

        unordered_map<Node*,Node*>ump;

        ump[root]=new Node(root->val);

        qu.push(root);

        Node* nd;
        Node* nwnd;
        Node* nwcld;

        while(!qu.empty())
        {

            nd=qu.front();
            nwnd=ump[nd];

            for(auto cld:nd->children)
            {

                nwcld=new Node(cld->val);
                ump[cld]=nwcld;
                nwnd->children.push_back(nwcld);
                qu.push(cld);
            }


            qu.pop();
        }



        return ump[root];

    }
};