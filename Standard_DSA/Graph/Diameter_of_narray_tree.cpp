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
protected:
     int diamtr=0;

     int height(Node* node)
     {

         if(node->children.size()==0)
         return 0;


         // select the top two largest heights

         int maxHeight1=0,maxHeight2=0;

         for(Node* child:node->children)
         {

           int parentHeight=height(child)+1;

           if(parentHeight>maxHeight1)
           {
            maxHeight2=maxHeight1;
            maxHeight1=parentHeight;
           }
           else if(parentHeight>maxHeight2)
           {
             maxHeight2=parentHeight;
           }

           // calculate the distance between the two farthest leaves nodes
           int distance=maxHeight1+maxHeight2;
           diamtr=max(diamtr,distance);
         }
         return maxHeight1;
     }

public:
    int diameter(Node* root)
    {
        diamtr=0;
        height(root);
        return diamtr;
    }
};