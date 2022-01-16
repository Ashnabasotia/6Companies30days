int helper(Node* root, int X, int& sum)
{
    if(root == NULL)
       return 0; 
     
    int left  =  helper(root->left,X,sum);
    int right =  helper(root->right,X,sum);
    if(root->data+left+right == X)
        sum += 1;
    return root->data+left+right;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int sum = 0;
	helper(root,X,sum);
	return sum;
}
