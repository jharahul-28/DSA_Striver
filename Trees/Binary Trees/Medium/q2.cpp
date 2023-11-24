/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int rec(TreeNode* node, int len){
        if(node==nullptr){
            if(len==-1)
            return -1;
            else 
            return len;
        }
        int l=rec(node->left, len+1);
        if(l==-1) return -1;
        int r=rec(node->right, len+1);
        if(r==-1 || abs(l-r)>1)
        return -1;
        return max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        int dif=rec(root, 1);
        if(dif==-1)
        return false;
        else return true;
    }
};