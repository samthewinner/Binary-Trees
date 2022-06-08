int solve(Node* root){
        if(!root) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == -1 || r == -1)return -1;
        if(abs(l-r) > 1) return -1;
        return 1+max(l,r);
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(!root){
            return true;
        }
        if(solve(root) == -1)return false;
        return true;
        
    }
