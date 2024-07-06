class Solution {
public:

    bool islocalmaxima(ListNode* prev,ListNode* node,ListNode* next)
    {
        if(node->val>prev->val && node->val>next->val)
        return true;
        else
        return false;
    }

    bool islocalminima(ListNode* prev,ListNode* node,ListNode* next)
    {
        if(node->val<prev->val && node->val<next->val)
        return true;
        else
        return false;
    }


    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

       int prev_crtcl=-1;
       int first_crtcl=-1;

       int min_distance=1e5;
       int max_distance=-1;

       int distance=0;
       ListNode* node;
       ListNode* prev;

       ListNode* next;

       prev=head;
       node=head->next;

       while(node->next!=NULL)
       {
          distance++;
          next=node->next;
          if(islocalmaxima(prev,node,next))
          {
             if(first_crtcl==-1)
             {
                first_crtcl=distance;
                prev_crtcl=distance;
             }
             else
             {
               min_distance=min(min_distance,distance-prev_crtcl);
               max_distance=distance-first_crtcl;
               prev_crtcl=distance;
             }
          }
          else if(islocalminima(prev,node,next))
          {
              if(first_crtcl==-1)
              {
                first_crtcl=distance;
                prev_crtcl=distance;
              }
              else
              {

               min_distance=min(min_distance,distance-prev_crtcl);
               max_distance=distance-first_crtcl;
               prev_crtcl=distance;

              }
          }
          prev=node;
          node=next;

       }

       min_distance=min_distance==1e5?-1:min_distance;

       return {min_distance,max_distance};



    }
};