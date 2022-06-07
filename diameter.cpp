int solve(Node* root,int* ans){
        if(!root) return 0;
        
        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);
        *ans = max(*ans,lh+rh);
        return 1 + max(lh,rh);
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(!root) return 0;
        int *ans = new int();
        *ans = 0;
        solve(root,ans);
        return 1+*ans;
    }
