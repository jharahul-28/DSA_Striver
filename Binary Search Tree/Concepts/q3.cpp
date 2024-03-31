/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
int minVal(Node* root){
	if(root==nullptr) return -1;
	// Write your code here.
	while(root!=nullptr){
		if(root->left == nullptr) return root->data;
		root=root->left;
	}
}