vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        map<int,int>m;
        m.insert({0,root->data});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front().first;
                int idx = q.front().second;
                q.pop();
                if(temp->left) {
                        m[idx-1] = temp->left->data;
                    q.push({temp->left,idx-1});
                }
                if(temp->right){
                    m[idx+1] = temp->right->data;
                    q.push({temp->right,idx+1});
                }
            }
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
    }
