class Cmp
{

    public:
    bool operator()(pair<double,int>&a,pair<double,int> &b)
    {
         return b.first<a.first;
    }
};

class Solution {
public:
    void inordertraversal(TreeNode* root,vector<int>&tree)
    {
        if(root==NULL)
        return;

        inordertraversal(root->left,tree);
        tree.push_back(root->val);
        inordertraversal(root->right,tree);


    }
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {

       vector<int>tree;

       inordertraversal(root,tree);

       priority_queue<pair<double,int>,vector<pair<double,int>>,Cmp>pq;

       for(int i=0;i<tree.size();i++)
       {
        pq.push({abs(tree[i]-target),i});
       }

       vector<int>ans;

       while(ans.size()<k)
       {
         auto pr=pq.top();
         pq.pop();
         ans.push_back(tree[pr.second]);
       }

       return ans;
    }
};
//////////////////////////---------------------/////////////------------------//////////////-------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Cmp
{

    public:
    bool operator()(pair<double,int>&a,pair<double,int> &b)
    {
         return b.first<a.first;
    }
};

class Solution {
public:
    void inordertraversal(TreeNode* root,vector<int>&tree)
    {
        if(root==NULL)
        return;

        inordertraversal(root->left,tree);
        tree.push_back(root->val);
        inordertraversal(root->right,tree);


    }
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {

       vector<int>tree;

       inordertraversal(root,tree);

       int start,i=0;
       double minDiff=numeric_limits<double>::max();
       for(i=0;i<tree.size();i++)
       {

          if(abs(tree[i]-target)<minDiff)
          {
            minDiff=abs(tree[i]-target);
            start=i;
          }

       }

       int left=start;
       int right=start+1;

       while(right-left-1<k)
       {
           // Be careful to not to out of bounds
           if(left<0)
           {
            right+=1;
            continue;
           }

        if(right==tree.size() || abs(tree[left]-target)<=abs(tree[right]-target))
        {
            left-=1;
        }
        else
        {
            right+=1;
        }



       }

       vector<int>ans;

       for(i=left+1;i<right;i++)
       {
        ans.push_back(tree[i]);
       }

       return ans;

    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    void inordertraversal(TreeNode* root,vector<int>&tree,double& target,int& k,priority_queue<pair<double,int>>&pq)
    {
        if(root==NULL)
        return;



        inordertraversal(root->left,tree,target,k,pq);

        double diff=abs(root->val-target);

        pq.push({diff,root->val});

        if(pq.size()>k)
        pq.pop();

        inordertraversal(root->right,tree,target,k,pq);


    }
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {

       vector<int>tree;
       priority_queue<pair<double,int>>pq;

       inordertraversal(root,tree,target,k,pq);

       vector<int>ans;

       while(!pq.empty())
       {
        ans.push_back(pq.top().second);
        pq.pop();
       }

       reverse(ans.begin(),ans.end());
       return ans;
    }
};
///////////////

class Solution {
public:
    void inordertraversal(TreeNode* root,vector<int>&tree)
    {
        if(root==NULL)
        return;

        inordertraversal(root->left,tree);
        tree.push_back(root->val);
        inordertraversal(root->right,tree);


    }
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {

       vector<int>tree;
       inordertraversal(root,tree);

       int left=0;
       int right=tree.size()-k;

       while(left<right)
       {
          int mid=(left+right)/2;

          if(abs(target-tree[mid+k])<abs(target-tree[mid]))
          {
            left=mid+1;
          }
          else
          {
            right=mid;
          }

       }
       vector<int>ans;
       for(int i=left;i<left+k;i++)
       {
        ans.push_back(tree[i]);
       }

       return ans;

    }


};
/////////////////////////////
class Solution {
public:
void inordertraversal(TreeNode* root,vector<int>&tree)
    {
        if(root==NULL)
        return;

        inordertraversal(root->left,tree);
        tree.push_back(root->val);
        inordertraversal(root->right,tree);


    }
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {

       vector<int>tree;

       inordertraversal(root,tree);

       int start,i=0;
       double minDiff=numeric_limits<double>::max();
       int low=0;
       int high=tree.size()-1;
        start=high;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(tree[mid]>target)
            {
                start=mid;
                high=mid-1;
            }
            else
            {
               low=mid+1;
            }

        }

        if(start!=0)
        {
           if(abs(tree[start-1]-target)<abs(tree[start]-target))
           {
            start=start-1;
           }
        }

       int left=start;
       int right=start+1;

       while(right-left-1<k)
       {
           // Be careful to not to out of bounds
           if(left<0)
           {
            right+=1;
            continue;
           }

           if(right==tree.size() || abs(tree[left]-target)<=abs(tree[right]-target))
        {
            left-=1;
        }
        else
        {
            right+=1;
        }



       }

       vector<int>ans;

       for(i=left+1;i<right;i++)
       {
        ans.push_back(tree[i]);
       }

       return ans;

    }
};
