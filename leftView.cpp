vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*>q;
    q.push(root);
    ans.push_back(root->data);
    while(!q.empty()){
        bool gotAns = false;
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left){
                if(!gotAns){
                    gotAns=true;
                    ans.push_back(temp->left->data);
                }
                q.push(temp->left);
            }
            if(temp->right){
                if(!gotAns){
                    gotAns=true;
                    ans.push_back(temp->right->data);
                }
                q.push(temp->right);
            }
        }
        
    }
    return ans;
}
