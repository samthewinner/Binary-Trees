int solve(TreeNode<int>* root,int &mxsum){
    if(!root) return 0;

    
    int lsum = solve(root->left,mxsum);
    int rsum = solve(root->right,mxsum);
    if(lsum + rsum +root->data > mxsum) mxsum = lsum + rsum +root->data;
    return lsum + rsum + root->data;
}

int largestSubtreeSum(TreeNode<int> *root) {
	if(!root) return 0;

    int mxsum = INT_MIN;    
    solve(root,mxsum);

    return mxsum;
    
                    
}
