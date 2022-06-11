if(!root) return 0;
        sum = sum+root->data;
        if(depth >= mxDepth){
            mxDepth = depth;
            if(sum > mxsum) mxsum = sum;
        }
        solve(root->left,sum,mxsum,depth+1,mxDepth);
        solve(root->right,sum,mxsum,depth+1,mxDepth);
        return mxsum;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum,mxsum,depth,mxDepth;
        sum = mxsum = depth = mxDepth = 0;
        return solve(root,sum,mxsum,depth,mxDepth);
    }
