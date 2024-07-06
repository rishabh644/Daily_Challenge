Node* connect(Node* root) {

        if(root==NULL)
        return root;

        queue<Node*>qu;

        qu.push(root);

        Node* prev;
        Node* curr;

        while(!qu.empty())
        {
            int sz=qu.size();

            int i=1;

            prev=NULL;

            while(i<=sz)
            {
                curr=qu.front();

                qu.pop();

                if(prev!=NULL)
                prev->next=curr;

                prev=curr;

                if(curr->left!=NULL)
                qu.push(curr->left);

                if(curr->right!=NULL)
                qu.push(curr->right);

                i+=1;
            }

        }

        return root;

    }