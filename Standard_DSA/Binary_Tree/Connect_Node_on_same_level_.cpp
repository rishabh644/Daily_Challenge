Node* connect(Node* root){

    if(root==NULL)
        return root;

    Node *currentLevelStart = root; // start with the root of the tree

    while(currentLevelStart!=NULL)
    {

        Node *current = currentLevelStart;
        Node *nextLevelStart = NULL;
        Node *prev = NULL;

        while(current!=NULL)
        {
          // Connect the left child

          if(current->left!=NULL)
          {
              if(prev!=NULL){
                  prev->next = current->left;
              }
              else
              {
                  nextLevelStart = current->left;
              }

              prev = current->left;
          }

           // Connect the right child


          if(current->right!=NULL){

                if(prev!=NULL){
                    prev->next = current->right;
                 }
                 else
                 {
                     nextLevelStart = current->right;
                 }

                 prev = current->right;
                                 }

           // Move to the next node in the current level using the next pointer

            current = current->next;
        }

           // Move to the next level

        currentLevelStart = nextLevelStart;

    }

    return root;
}