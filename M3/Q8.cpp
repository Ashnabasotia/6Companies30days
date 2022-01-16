void connect(Node *root)
    {
       // Your Code Here
       if(root == NULL)
        return;
       queue <Node*> Q;
       Q.push(root);
       Q.push(NULL);
       
       while(!(Q.empty()) && Q.front())
       {
           Node* node = Q.front();
           Q.pop();
          
           node->nextRight = Q.front();
           
           if(node->left)
             Q.push(node->left);
           
           if(node->right)
             Q.push(node->right);
            
           if(!Q.front())
            {
                Q.pop();
                Q.push(NULL);
            }
            
       }
       
    }    