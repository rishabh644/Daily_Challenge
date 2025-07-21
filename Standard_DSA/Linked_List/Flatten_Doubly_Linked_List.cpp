/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head)
    {
         if(head==NULL)
         return head;

         Node* pseudoHead=new Node(0,NULL,head,NULL);

         flattenDFS(pseudoHead,head);

         pseudoHead->next->prev=NULL;

         return pseudoHead->next;
    }

    Node* flattenDFS(Node* prev,Node* curr)
    {
          if(curr==NULL)
          return prev;

          curr->prev=prev;
          prev->next=curr;

          // the curr.next would be tempered in the recursive function

          Node* tempNext=curr->next;

          Node* tail=flattenDFS(curr,curr->child);
          curr->child=NULL;

          return flattenDFS(tail,tempNext);

    }



};
/////////////////////////////////////---------------------------////////////////////////////------------------------------/////////////////////////------------------------//////////////////////////----------------------///////////////////////////////-------------------------
class Solution {
public:

    Node* flatten(Node* head)
    {
        if(head==NULL)
        return head;

        Node* pseudoHead=new Node(0,NULL,head,NULL);

        Node *curr,*prev=pseudoHead;

        stack<Node*>st;

        st.push(head);

        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            prev->next=curr;
            curr->prev=prev;
            if(curr->next!=NULL)
            st.push(curr->next);

            if(curr->child!=NULL)
            {
                st.push(curr->child);
                curr->child=NULL;
            }
            prev=curr;
        }

        pseudoHead->next->prev=NULL;

        return pseudoHead->next;

    }




};