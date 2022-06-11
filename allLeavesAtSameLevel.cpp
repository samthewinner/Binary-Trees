bool isLeaf(Node* root) {
        if(!root) return true;
        return !root->left && !root->right;
    }
    
    bool check(Node *root)
    {
        if(!root) return true;
        if(isLeaf(root)) return true;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            bool leafFound = false;
            bool notFound = false;
            for(int i=0;i<s;i++){
                Node* temp = q.front();
                q.pop();
                if(isLeaf(temp)){
                    leafFound=true;
                    if(leafFound && notFound) return false;
                    
                }
                else{
                    notFound = true;
                    if(leafFound && notFound) return false;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
        }
        return true;
    }
