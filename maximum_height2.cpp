 int  solve(TreeNode* root,int length){
        if(!root) {
            return 0;
        }
        
        int l = solve(root->left,length+1);        
        int r = solve(root->right,length+1);
        return 1+max(l,r);
    }
    
    int maxDepth(TreeNode* root) {
        // if(!root) return 0;                
        return solve(root,1);
        
        
    }
