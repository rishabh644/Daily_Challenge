/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

//     // Encodes a tree to a single string.
//    void rserialize(TreeNode* root,string& str)
//    {
//       if(root==NULL)
//       str=str+"N"+",";
//       else
//       {
//         str=str+to_string(root->val)+",";
//         rserialize(root->left,str);
//         rserialize(root->right,str);
//       }

//    }
//    string serialize(TreeNode* root)
//    {    string str="";
//         rserialize(root,str);
//         return str;
//    }

//     // Decodes your encoded data to tree.

//     TreeNode* rdeserialize(vector<string>&tokens,int& ind)
//     {    ind+=1;
//          if(tokens[ind]=="N")
//          return NULL;
//          else
//          {
//             int val=stoi(tokens[ind]);
//             TreeNode* node=new TreeNode(val);
//             node->left=rdeserialize(tokens,ind);
//             node->right=rdeserialize(tokens,ind);
//             return node;
//          }
//     }
//     TreeNode* deserialize(string data)
//     {

//         vector<string>tokens;
//         string token;
//         stringstream ss(data);

//         while(getline(ss,token,','))
//         {
//             tokens.push_back(token);
//         }
//         int ind=-1;
//         return rdeserialize(tokens,ind);

//     }
// Encodes a tree to a single string.
    void rserialize(TreeNode* root, stringstream& ss) {
        if (root == NULL) {
            ss << "N,";
        } else {
            ss << root->val << ",";
            rserialize(root->left, ss);
            rserialize(root->right, ss);
        }
    }

    string serialize(TreeNode* root) {
        stringstream ss;
        rserialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* rdeserialize(istringstream& ss) {
        string token;
        getline(ss, token, ',');

        if (token == "N") {
            return NULL;
        }

        int val = stoi(token);
        TreeNode* node = new TreeNode(val);
        node->left = rdeserialize(ss);
        node->right = rdeserialize(ss);
        return node;
    }

    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return rdeserialize(ss);
    }
};