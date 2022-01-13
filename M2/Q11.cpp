void preorder (Node* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
        return;
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector <int> ans;
        preorder(root, ans);
        return ans;
    }
    Node* helper(int& i, vector<int> &A)
    {
        if(A[i] == -1)
            return NULL;
        Node* node = new Node(A[i]);
        node->left = helper(++i,A);
        node->right = helper(++i,A);
        return node;
        
        
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int i=0;
       return helper(i,A);
    }