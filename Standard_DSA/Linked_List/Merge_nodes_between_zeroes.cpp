ListNode* mergeNodes(ListNode* head) {


        ListNode* mo_head=head;
        ListNode* tail=head;
        ListNode* prev;
        int sum=0;

        ListNode* node=head->next;

        while(node!=NULL)
        {
            sum+=node->val;

            if(node->val==0)
            {
                tail->val=sum;
                tail->next=node;
                prev=tail;
                tail=node;
                sum=0;
            }



            node=node->next;
        }

        prev->next=NULL;

        return mo_head;

    }

    ListNode* mergeNodes(ListNode* head) {

     // Initialize a sentinel/dummy node with the first non-zero value

     ListNode* modify=head->next;
     ListNode* nextSum=modify;

     while(nextSum) {

         int sum=0;
         // Find the sum of all nodes until you encounter a 0

         while(nextSum->val!=0){
            sum+=nextSum->val;
            nextSum=nextSum->next;
         }

         // Assign the sum to the current node's value.
         modify->val=sum;
         // Move nextSum to the first non-zero value of the next block

         nextSum=nextSum->next;

         // Move modify also to this node.

         modify->next=nextSum;

         modify=modify->next;


     }

     return head->next;


    }
/////
