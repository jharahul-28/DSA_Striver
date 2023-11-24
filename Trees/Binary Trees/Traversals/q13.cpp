/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector <vector<int>> ans;
    vector<int> pre;
    vector<int> inO;
    vector<int> post;
    stack<pair<TreeNode *, int>>s;
    s.push({root,1});
    int freq;
    while(!s.empty()){
        auto it=s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first()->left!=nullptr)
            s.push({it.first()->left,1});
        }
        else if(it.second()==2){
            inO.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first()->right!=nullptr)
            s.push({it.first()->right,1});
        }
        else{
            post.push_back(it.first->val);
        }
    }
    ans.push_back(inO);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}