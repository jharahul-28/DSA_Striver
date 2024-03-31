/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int suc=-1, pre=-1;
    auto cur=root;
    while(cur!=NULL){
        if(cur->data < key){
            cur=cur->right;
        }
        else if(cur->data==key) {
            suc=(cur->right!=NULL)? cur->right->data : suc;
            break;
        }
        else{
            suc=((suc==-1) ? (cur->data) : min(suc,cur->data));
            cur=cur->left;
        }
    }
    cur=root;
    while(cur!=NULL){
        if(cur->data > key) cur=cur->left;
        else if(cur->data==key) {
            pre=(cur->left!=NULL)? cur->left->data : pre;
            break;
        }
        else{
            pre=((pre==-1) ? (cur->data) : max(pre,cur->data));
            cur=cur->right;
        }
    }
    return {pre,suc};
}