    bool nodeCheck(TreeNode* l, TreeNode* r){
        if(l==nullptr && r==nullptr) return true;
        if(l==nullptr || r==nullptr) return false;
        return (l->val==r->val && nodeCheck(l->left,r->right) && nodeCheck    (l->right,r->left));
    }
    bool isSymmetric(TreeNode* root) {
        return nodeCheck(root,root);
    }