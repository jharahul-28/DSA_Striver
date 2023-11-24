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
            return len;
        }
        int l=rec(node->left, len+1);
        int r=rec(node->right, len+1);
        return max(l,r);
    }
public:
    int maxDepth(TreeNode* root) {
        return (rec(root, 1)-1);
    }
};