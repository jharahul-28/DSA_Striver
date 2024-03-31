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
    void trav(TreeNode* node, vector<int> &ans){
        if(node==nullptr) return;
        trav(node->left,ans);
        ans.push_back(node->val);
        trav(node->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> iot;
        trav(root,iot);
        int a=0, b=iot.size()-1;
        while(a<b){
            if((iot[a]+iot[b])==k) return true;
            else if((iot[a]+iot[b])>k) b--;
            else a++;
        }
        return false;
    }
};