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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        bool l2r=true;
        while(!q.empty()){
            int len=q.size();
            vector<int> ds(len);
            for(int i=0;i<len;i++){
                auto temp=q.front();
                q.pop();
                if(l2r)
                ds[i]=temp->val;
                else
                ds[len-1-i]=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            l2r=!l2r;
            ans.push_back(ds);
        }
        return ans;
    }
};