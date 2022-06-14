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
    
    int getDist(Node* root,int k,int dist){
        if(!root) return -1;
        
        if(root->data == k){
            return dist;
        }
        int lval = getDist(root->left,k,dist+1);
        int rval = getDist(root->right,k,dist+1);
        
        if(lval == -1 and rval == -1) return -1;
        if(lval != -1) return lval;
        return rval;
    }
    
    int findDist(Node* root, int a, int b) {
        Node* lcaNode = lca(root,a,b);
        int ldist = getDist(lcaNode,a,0);
        int rdist = getDist(lcaNode,b,0);
        return ldist + rdist ;
    }
