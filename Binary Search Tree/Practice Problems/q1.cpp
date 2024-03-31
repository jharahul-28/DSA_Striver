#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    while(node!=NULL){
        if(node->data == x) return x;
        else if(node->data < x) node=node->right;
        else {
            if(ans==-1 || node->data<ans) ans=node->data;
            node=node->left;
        }
    }
    return ans;
}