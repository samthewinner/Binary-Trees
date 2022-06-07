vector<int> ans;
    if(!root) return ans;
    stack<int> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int cap = q.size();
        for(int i=0;i<cap;i++){
            Node * n = q.front();
            q.pop();
            s.push(n->data);
            if(n->right) q.push(n->right);
            if(n->left) q.push(n->left);
            
        }        
        
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
