bool isLeaf(Node* root){
      return !root->left && !root->right;
  }
  
  string checkRight(Node* root,set<string> &subtrees,int &ans){
      if(!root) return "";
      if(isLeaf(root)){
          string s = "";
          s=s+root->data;
          return s;
      }
      string lside = checkRight(root->left,subtrees,ans);
      string rside = checkRight(root->right,subtrees,ans);
      if(lside == "duplicateExist" || rside == "duplicateExist") return "duplicateExist";
      string ret = lside + root->data + rside;
      if(subtrees.count(ret)) {
          ans = 1;
          return "duplicateExist";
      }
      return ret;
  }
  
  string getSubTree(Node* root,set<string> &subtrees){
      if(!root) return "";
      if(isLeaf(root)){ 
           string s = "";
          s=s+root->data;
          return s;
      }
      
      string lside = getSubTree(root->left,subtrees);
      string rside = getSubTree(root->right,subtrees);
      string ret = lside + root->data + rside;
      subtrees.insert(ret);
      return ret;
      
  }
  
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         if(!root) return 0;
         set<string> s;
         getSubTree(root->left,s);
         if(s.empty()) return 0;
         int ans = 0;
          checkRight(root->right,s,ans);
          return ans;
    }
