TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.size() == 0 || pre.size() != in.size()){
            return nullptr;
        }
        
        int value = pre[0];
        TreeNode* root = new TreeNode(value);
        if(pre.size() == 1){
            return root;
        }
        
        //在中序遍历中找出根节点所在位置
        auto pos = find(in.begin(), in.end(), value);
        if(pos == in.end()){
            return nullptr;
        }
        
        int leftSize = pos - in.begin();
        int rightSize = in.end() - pos - 1;
        root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + leftSize), 
                                           vector<int>(in.begin(), in.begin() + leftSize));
        root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + leftSize, pre.end()), 
                                            vector<int>(in.begin() + leftSize + 1, in.end()));
        return root;  
    }