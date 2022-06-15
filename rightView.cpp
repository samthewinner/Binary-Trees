// method 1: 
vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
       queue<Node*> q;
       q.push(root);
       ans.push_back(root->data);
       while(!q.empty()){
           bool gotAns = false;
           int n = q.size();
           for(int i=0;i<n;i++){
               Node* temp = q.front();
               q.pop();
               if(temp->right){
                   if(!gotAns){
                       gotAns = true;
                       ans.push_back(temp->right->data);
                   }
                   q.push(temp->right);
               }
               if(temp->left){
                   if(!gotAns){
                       gotAns = true;
                       ans.push_back(temp->left->data);
                   }
                   q.push(temp->left);
               }
           }
    }
    return ans;
    }

//method 2:
vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
       queue<Node*> q;
       q.push(root);
       ans.push_back(root->data);
       while(!q.empty()){
           int s = q.size();
           int tempVal=INT_MIN;
           for(int i=0;i<s;i++)
           {
               Node* temp = q.front();q.pop();
                if(temp->left){
                    q.push(temp->left);
                    tempVal = temp->left->data;
                }
                if(temp->right){
                    q.push(temp->right);
                    tempVal = temp->right->data;
                }
           }
           if(tempVal != INT_MIN) ans.push_back(tempVal);
    }
    return ans;
    }
