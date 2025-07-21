struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key,int val)
    {
       this->key=key;
       this->val=val;
    }

};

class LRUCache {
private:
    int sz;
    int csz;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>dic;
public:
    LRUCache(int capacity)
    {
        sz=capacity;
        csz=0;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key)
    {
        if(dic.count(key)==0)
        {
            return -1;
        }
        else
        {
            Node* curr=dic[key];
            int val=curr->val;
            remove_node(curr);
            insert_at_head(curr);
            return val;
        }

    }

    void put(int key, int value)
    {
        Node* curr;
        if(dic.count(key)==0)
        {
           if(csz==sz)
           { curr=tail->prev;
             remove_node(curr);
             dic.erase(curr->key);
             delete(curr);
             csz-=1;
           }
           csz+=1;
           curr=new Node(key,value);
           dic[key]=curr;
        }
        else
        {
            curr=dic[key];
            curr->val=value;
            remove_node(curr);
        }
        insert_at_head(curr);
    }

    void remove_node(Node* curr)
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }

    void insert_at_head(Node* curr)
    {
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
            curr->prev=head;
    }
};