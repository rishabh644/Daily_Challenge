#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int val,Node* left,Node* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

struct Node* insert_node(int arr[],int i,int l)
{
       if(i>=l)
           return NULL;
       struct Node *root;
       root = new Node(arr[i]);
       root->left = insert_node(arr, 2 * i + 1, l);
       root->right = insert_node(arr, 2 * i + 2, l);
       return root;
}

struct Node* construct_complete_binary_tree(int arr[],int ind,int len)
{
    return insert_node(arr,0, len);
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

    root = construct_complete_binary_tree(arr,0, len);
    cout << "Level Order Traversal" << endl;
    level_order_traversal(root);
    cout << "\nPre Order Traversal" << endl;
    pre_order_traversal(root);
    return 0;
}