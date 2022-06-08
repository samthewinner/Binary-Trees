vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*>q;
    Node*node=root;
    while(1){
        ans.push_back(node->data);
        if(node->left) q.push(node->left);
        if(node->right) node = node->right;
        else{
            if(q.empty()) break;
            node = q.front();
            q.pop();
        }
            
    }
    return ans;
    
}
