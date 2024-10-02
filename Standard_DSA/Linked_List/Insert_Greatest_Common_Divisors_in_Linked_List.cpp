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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {

        ListNode* curr=head->next;
        ListNode* prev=head;

        while(curr)
        {
           int a=prev->val;
           int b=curr->val;

           int gcd_=gcd(a,b);

           ListNode* newnode=new ListNode(gcd_);

           prev->next=newnode;
           newnode->next=curr;

           prev=curr;
           curr=curr->next;
        }

        return head;



    }
};