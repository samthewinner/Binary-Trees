void solve(Node* root,vector<int>&temp,int val,bool &found){
    
    if(!root) return ;
    
    
    temp.push_back(root->data);
    
    if(root->data == val) {
        found = true;
        return;
    }
    if(found) return;
    solve(root->left,temp,val,found);
    if(found) return;
    solve(root->right,temp,val,found);
    if(found) return;
    temp.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    bool found = false;
    solve(root,path,node,found);
    if(k > path.size()-1) return -1;
    return path[path.size()-1-k];
}
