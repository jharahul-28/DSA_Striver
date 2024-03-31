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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->left!=nullptr && cur->left->val==key) {
                cur->left=helper(cur->left);
                break;
            }
            else if(cur->right!=nullptr && cur->right->val==key) {
                cur->right=helper(cur->right);
                break;
            }
            else if(cur->val > key) cur=cur->left;
            else cur=cur->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* cur){
        if(cur->left==nullptr) return cur->right;
        if(cur->right==nullptr) return cur->left;
        TreeNode* leftNode =cur->left;
        TreeNode* rightEnd=cur->right;
        while(rightEnd->left!=nullptr){
            rightEnd=rightEnd->left;
        }
        rightEnd->left=leftNode;
        return cur->right;
    }
};