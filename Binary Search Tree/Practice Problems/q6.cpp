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
    void inOT(TreeNode* root, vector<int>& v){
        if(root==nullptr) return;
        if(root->left) {
            inOT(root->left, v);
        }
        v.push_back(root->val);
        if(root->right) {
            inOT(root->right, v);
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inOT(root,v);
        vector<int>v1(v.size());
        for(int i=0;i<v.size();i++){
            v1[i]=v[i];
            if(i!=0){
                if(v[i]<=v[i-1]) return false;
            }
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<v.size();i++){
            if(v1[i]!=v[i]) return false;
        }
        return true;
    }
};