bool solve(Node* root,int n1,int n2,Node**ans,bool &ansfound){
        if(!root) return false;
        
        bool l = solve(root->left,n1,n2,ans,ansfound);
        bool r = solve(root->right,n1,n2,ans,ansfound);
        
        if(ansfound) return true;
        
        if(l && r){
            ansfound = true;
            *ans = root;
            return true;
        }
        
        int val = root->data;
        
        if(val == n1 || val == n2){
            if(l || r)
            {
                *ans = root;ansfound = true;
            }
            return true;
        }
        
        return l || r;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        Node* ans = NULL;
        bool ansfound=false;
       solve(root,n1,n2,&ans,ansfound);
       return ans;
    }
