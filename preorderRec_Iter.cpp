void preorderIter(Node* root)
{
  stack<Node*> s;
  s.push(root);
  while(!s.empty()){
    Node* temp = s.top();
    s.pop();
    if(temp->right)s.push(temp->right);
    if(temp->left)s.push(temp->left);
  }
}
