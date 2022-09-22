void solve(TreeNode* root,TreeNode* &head,TreeNode* &temp){
        if(!root)return;
        solve(root->right,head,temp);
        solve(root->left,head,temp);
        root->left = root->right = NULL;
        if(!head) head = root;
        if(temp) temp -> right = root;
        temp = root;
        
    }
    
    void flatten(TreeNode* root) {
        TreeNode* head = NULL;
        TreeNode* temp = NULL;
        solve(root,head,temp);
        TreeNode* prev,*nex;
        prev = NULL;temp = head;
        while(temp){
            nex = temp->right;
            temp->right = prev;
            prev = temp;
            temp = nex;
        }
        
    }
