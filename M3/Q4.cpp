vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int n1 = r%2==0? r/2: (r/2)+1;
        int n2 = c%2==0? c/2: (c/2)+1;
        vector<int>ans;
         int R_s = 0;
         int C_s = 0;
         int R_e = r-1;
         int C_e = c-1;
        for(int i=0 ; i<min(n1,n2); i++)
        {
            //top side of square-one
            int j,k,l,m;
            for(j=C_s; j<=C_e; j++)
            {
                if(R_s <= R_e)
                    ans.push_back(matrix[R_s][j]);
            }
            R_s++;
            //right-side
            for( k=R_s; k<=R_e; k++)
            {
                if(C_e >= C_s)
                    ans.push_back(matrix[k][C_e]);
            }
            C_e--;
            //bottom
            for( l=C_e; l>=C_s; l--)
            {
                if(R_s <= R_e)
                     ans.push_back(matrix[R_e][l]);
            }
            R_e--;
               
            //left
            for( m=R_e; m>=R_s; m--)
            {
                if(C_s<=C_e)
                    ans.push_back(matrix[m][C_s]);
            }
            C_s++;
        }
        
        return ans;
    }