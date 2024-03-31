/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxi=max(p->val,q->val);
        int mini=min(p->val,q->val);
        while(root!=NULL){
            if(root->val==maxi || root->val==mini) return root;
            if(mini<root->val && maxi>root->val) return root;
            else{
                if(mini>root->val) root=root->right;
                else if(maxi<root->val) root=root->left;
            }
        }
        return root;
    }
};