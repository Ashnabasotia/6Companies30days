void printAnswer (int i, int j, int n, vector<vector<int>>& bracket,char& name, string& ans)
    {
        if(i==j)
        {
            ans += name;
            name++;
            return;
        }
        ans += '(';
        printAnswer(i,bracket[i][j],n,bracket,name,ans);
        printAnswer(bracket[i][j]+1,j,n,bracket,name,ans);
        ans += ')';
    }
    void helper(int p[], int n, vector<vector<int>>& bracket)
    {
        int m[n][n];
        
        
        for(int i=1; i<n; i++)
            m[i][i] = 0;
        
        //L is chain length
        for(int L=2; L<n; L++)
        {
            for(int i=1; i<n-L+1; i++)
            {
                int j = i+L-1;
                m[i][j] = INT_MAX;
                for(int k=i; k<=j-1; k++)
                {
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
    }
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>> bracket(n,vector<int>(n));
        helper(p,n,bracket);
        char name = 'A';
        string ans = "";
        printAnswer(1,n-1,n,bracket,name,ans);
        return ans;
    }