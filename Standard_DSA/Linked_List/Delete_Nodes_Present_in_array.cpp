/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {

     unordered_set<int>ust(nums.begin(),nums.end());

     ListNode* prev=NULL;

     ListNode* node=head;

     ListNode* next;

     while(node!=NULL)
     {

        next=node->next;

        if(ust.find(node->val)!=ust.end())
        {
            if(prev==NULL)
            {
                head=next;
            }
            else
            {
                prev->next=next;
            }
        }
        else
        {
            prev=node;
        }

        node=next;

     }

     return head;

    }
};