    void solve(TreeNode* root,int* ans,int length){
        if(!root) return;
        
        solve(root->left,ans,length+1);
        if(length > *ans){
            *ans = length;
        }
        solve(root->right,ans,length+1);
    }
    
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int * l = new int();
        *l=INT_MIN;
        solve(root,l,0);
        return *l+1;
        
    }
