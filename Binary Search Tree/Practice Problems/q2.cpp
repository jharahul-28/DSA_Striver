int Floor(BinaryTreeNode<int> *node, int x)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	 int ans=-1;
     while(node!=NULL){
         if(node->data == x) return x;
         else if(node->data > x) node=node->left;
         else {
             if(ans==-1 || node->data>ans) ans=node->data;
             node=node->right;
         }
     }
     return ans;
}
