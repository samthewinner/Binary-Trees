 bool isLeaf(TreeNode* root){
        if(!root) return true;
        return !root->left && !root->right;
    }
    
    string solve(TreeNode* root,string &s){
        if(!root )  return "";
        if(isLeaf(root)) {
            s=s+to_string(root->val);
            return "";
        }
        s=s+to_string(root->val);
        
        s=s+"(";
        solve(root->left,s);
        s=s+")";
        if(root->right){
            s=s+"(";
            solve(root->right,s);
        s=s+")"; }
                       
        return "";
    }
    
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string s = "";
        solve(root,s);
        return s;
    }
