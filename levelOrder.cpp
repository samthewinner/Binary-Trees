 vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        if(!node) return ans;
      queue<Node*>q;
      q.push(node);
      while(!q.empty()){
          int s = q.size();
          for(int i=0;i<s;i++){
          Node* temp = q.front();
          q.pop();
          ans.push_back(temp->data);
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
          }
      }
      return ans;
    }
