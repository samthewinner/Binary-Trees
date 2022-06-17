// Node* solve(int in[],int pre[],int n,int l,int r,int*idx){
//         if(l == -1 || r == n) return NULL;
//           if(l == r) {
//               Node* temp = new Node(pre[*idx]);
//               (*idx)++;
//               temp->left = temp->right = NULL;
//               return temp;
//           }
//             Node* temp = new Node(pre[*idx]);
//             int val = pre[*idx];
//             (*idx)++;
//             int i;
//             for( i=l;i<r;i++){
//                 if(in[i] == val) break;
//             }
//             int index = i;
//             if(index == l) l = -1;
//             if(index == r) r = n;
//             temp->left = solve(in,pre,n,l,index-1,idx);
//             temp->right = solve(in,pre,n,index+1,r,idx);
//             return temp;
//     }
    
//     Node* buildTree(int in[],int pre[], int n)
//     {
//         int* idx = new int();
//         *idx = 0;
//           return solve(in,pre,n,0,n-1,idx);
            
            
//     }


Node* solve(int in[],int pre[],int n,int l,int r,int &idx,map<int,int>&m){
        if(l>r) return NULL;
            Node* temp = new Node(pre[idx]);
            int val = pre[idx++];
            int index = m[val];
            temp->left = solve(in,pre,n,l,index-1,idx,m);
            temp->right = solve(in,pre,n,index+1,r,idx,m);
            return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
    int idx = 0;
        map<int,int>m;
        for(int i=0;i<n;i++)
            m[in[i]] = i;
        return solve(in,pre,n,0,n-1,idx,m);
    }
