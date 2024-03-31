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
    void inOT(TreeNode* root, vector<int>& v, int k){
        if(k==0) return;
        if(root==nullptr) return;
        if(root->left) {
            inOT(root->left, v,k);
        }
        v.push_back(root->val);
        k--;
        if(root->right) {
            inOT(root->right, v,k);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOT(root,v,k);
        return v[k-1];
    }
};