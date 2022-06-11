bool isLeaf(Node* root){
        return !root->right && !root->left;
    }
    
    int solve(Node* root){
        
        if(!root) return 0;
        if(isLeaf(root)) return root->data;
        
        int lsum = solve(root->left);
        int rsum = solve(root->right);
        
        if(lsum == INT_MIN || rsum == INT_MIN) return INT_MIN;
        
        int val = root->data;
        if(lsum + rsum != val) return INT_MIN;
        
        return val + lsum + rsum;
    }
    
    bool isSumTree(Node* root)
    {
        if(solve(root) == INT_MIN) return false;
        return true;
    }
