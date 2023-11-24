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
    int dia=1;
    int diam(TreeNode* root){
        if(root==nullptr){
            return 0;        
        }
        int ld=diam(root->left)+1;
        int rd=diam(root->right)+1;
        int d=max(ld,rd);
        dia=max(dia,ld+rd-2);
        return d;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))
        return 0;
        int d=diam(root);
        return dia;
    }
};