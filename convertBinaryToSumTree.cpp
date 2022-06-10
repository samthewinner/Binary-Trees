 bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    
    int solve(Node* root){
        if(!root) return 0;
        if(isLeaf(root)){
            int val = root->data;
            root->data = 0;
            return val;
        }
        int lsum = solve(root->left);
        int rsum = solve(root->right);
        
        int val = root->data;
        root->data = lsum + rsum;
        return val+lsum + rsum;
        
    }
    
    void toSumTree(Node *node)
    {
        if(!node) return;
        solve(node);
    }
