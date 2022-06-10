void solve(Node* root,Node** prev,Node** head){
        if(!root) return ;
        solve(root->left,prev,head);
        if(!(*prev)) *head=root;
        else{
            (*prev)->right = root;
            root->left = *prev;
        }
        *prev = root;
        solve(root->right,prev,head);
        
    }
    
    Node * bToDLL(Node *root)
    {
        Node* head ,*prev;
        prev=head=NULL;
        solve(root,&prev,&head);
        return head;
        
    }
