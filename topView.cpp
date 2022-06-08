vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        map<int,int>m;
        m.insert({0,root->data});
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front().first;
                int idx = q.front().second;
                q.pop();
                if(temp->left){
                    if(!m.count(idx-1))
                        m.insert({idx-1,temp->left->data});
                q.push({temp->left,idx-1});
                }
                if(temp->right){
                    if(!m.count(idx+1))
                        m.insert({idx+1,temp->right->data});
                q.push({temp->right,idx+1});
                }
            }
        }
        for(auto it: m)
            ans.push_back(it.second);
        return ans;
    }
