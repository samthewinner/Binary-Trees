Node* lca(Node* root,int a,int b){
        
        if(!root) return NULL;
        
        if(root->data == a or root->data == b)
            return root;
        
        Node* lnode = lca(root->left,a,b);
        Node* rnode = lca(root->right,a,b);
        
        if(lnode and rnode) return root;
        if(!lnode && !rnode) return NULL;
        if(lnode) return lnode;
        return rnode;
        
    }
