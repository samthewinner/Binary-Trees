bool isLeaf(Node* root){
        return (!(root->left) && !(root->right));
    }
    void getLeft(Node* root,vector<int>&ans){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left){
                curr=curr->left;
            }
            else curr=curr->right;
        }
        
    }

    void getLeaf(Node* root,vector<int>&ans){
        if(!root) return;
        if(!(root->left) && !(root->right)) ans.push_back(root->data);
        getLeaf(root->left,ans);
        getLeaf(root->right,ans);
        return;
    }
    
    void getRight(Node* root,vector<int> &ans){
        stack<int>s;
        Node* temp = root->right;
        while(temp){
            if(!isLeaf(temp)) s.push(temp->data);
            if(temp->right) temp = temp->right;
            else temp = temp->left;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root) return ans;
        ans.push_back(root->data);
        if(!(root->left) && !(root->right)) return ans;
        getLeft(root,ans);
        getLeaf(root,ans);
        getRight(root,ans);
        return ans;
        
    }
