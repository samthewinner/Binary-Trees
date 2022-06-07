void postorderIter{
  stack<Node*>s;
  vector<int> postorder;
  Node* temp,*curr;
  curr=root;
  while(!s.empty()){
    if(curr){
      s.push(curr);
      curr=curr->left;
    }
    else{
      temp = st.top()->right;
      if(temp){
        curr=temp;
      }
      else{
        temp=s.top();
        s.pop();
        postorder.push_back(temp->data);
        while(!s.empty() && s.top()->right == temp){
          temp=s.top();
          s.pop();
          postorder.push_back(temp->data);
        }
      }
    }
  }
}
