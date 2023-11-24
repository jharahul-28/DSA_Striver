/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void getL(TreeNode<int> *node, vector<int>& l){
    if(node->left==nullptr && node->right==nullptr){
        return;
    }
    l.push_back(node->data);
    if(node->left)
    getL(node->left,l);
    else
    getL(node->right,l);
}

void getLeaf(TreeNode<int> *node, vector<int>& leaf){
    if(node->left==nullptr && node->right==nullptr){
        leaf.push_back(node->data);
        return;
    }
    if(node->left)
    getLeaf(node->left,leaf);
    if(node->right)
    getLeaf(node->right,leaf);
}

void getR(TreeNode<int> *node, vector<int>& r){
    if(node->left==nullptr && node->right==nullptr){
        return;
    }
    if(node->right)
    getR(node->right,r);
    else
    getR(node->left,r);
    r.push_back(node->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    if(root->left)
    getL(root, ans);
    else
    ans.push_back(root->data);
    getLeaf(root, ans);
    if(root->right)
    getR(root->right, ans);
    return ans;
}
