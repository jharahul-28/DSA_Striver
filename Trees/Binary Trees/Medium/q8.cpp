class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, map<int,multiset<int>>> nodes;
        queue <pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* temp=p.first;
            int x= p.second.first;
            int y= p.second.second;
            nodes[x][y].insert(temp->val);
            if(p.first->left)
            todo.push({p.first->left,{x-1,y+1}});
            if(p.first->right)
            todo.push({p.first->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> ds;
            for(auto q: p.second){
                ds.insert(ds.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(ds);
        }
        return ans;
    }
};