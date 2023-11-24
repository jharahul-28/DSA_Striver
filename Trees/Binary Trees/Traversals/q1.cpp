/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createTree(vector<int>&arr){
    // Write your code here.
    queue <Node*> q;
    Node* root = new Node (arr[0]);
    q.push(root);
    for(int i=0;i<3 && !q.empty();i++){
        Node* temp=q.front();
        q.pop();
        Node* left=new Node(arr[2*i+1]);
        temp->left=left;
        q.push(left);        
        Node* right=new Node(arr[2*i+2]);
        temp->right=right;
        q.push(right);        
    }
    return root;
}