#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{

    int val;
    struct Node* left;
    struct Node *right;

    Node(int d,struct Node* l,struct Node* r)
    {
        val = d;
        left = l;
        right = r;
    }
    Node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};
struct Node* insert_node_in_BST(int val,struct Node* root)
{
     if(root==NULL)
     {
          return new Node(val);
     }
     if(val<root->val)
      {
          root->left = insert_node_in_BST(val, root->left);
      }
      else
      {
          root->right = insert_node_in_BST(val, root->right);
      }

      return root;
}

struct Node* construct_complete_binary_search_tree(int arr[],int l){

    struct Node *root = NULL;

    for (int i = 0; i < l;i++)
    {
        root = insert_node_in_BST(arr[i],root);
    }
    return root;
}

void level_order_traversal(struct Node* root)
{
    if(root==NULL)
        return;

    struct Node *temp;

    queue<struct Node *> qu;
    qu.push(root);


    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        cout << temp->val<<" ";
         if(temp->left!=NULL)
             qu.push(temp->left);
         if(temp->right!=NULL)
             qu.push(temp->right);
    }

}

void pre_order_traversal(struct Node *root)
{
    if(root==NULL)
        return;

    cout << root->val<<" ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

int main()
{
    int len;
    cout << "Enter length of array " << endl;
    cin >> len;
    int arr[len];

    cout << "Enter elements of array" << endl;

    for (int i = 0; i < len;i++)
    {

        cin >> arr[i];
    }

    struct Node *root;

    root = construct_complete_binary_search_tree(arr,len);
    cout << "Level Order Traversal" << endl;
    level_order_traversal(root);
    cout << "\nPre Order Traversal" << endl;
    pre_order_traversal(root);
    return 0;
}