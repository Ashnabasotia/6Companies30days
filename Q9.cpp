string printMinNumberForPattern(string S){
        // code here 
        int n = S.size();
        string ans;
        char next = '3';
        int idx;
        if(S[0] == 'D')
        {
            ans = "21";
            idx = 0;
        }
        if(S[0] == 'I')
        {
            ans = "12";
            idx = 1;
        }
        
        for(int i=1; i<n; i++)
        {
            if(S[i] == 'I' )
            {
                ans += next;
                next++;
                idx = i+1;
            }
            else{
                
                for(int j=idx; j<=i; j++)
                {
                    ans[j] = ans[j] +1;
                }
                char x = ans[i] - 1;
                ans += x;
                next++;
                
            }
        }
        
        return ans;
    }