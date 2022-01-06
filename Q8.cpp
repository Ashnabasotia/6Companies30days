int numDecodings(string s) {
        
        if(s[0] == '0')
            return 0;
        
        int n = s.size();
        
        if(n == 1)
            return 1;
        
        vector <int> ans(n+1,0);
        ans[0] = 1;
        ans[1] = 1;
        
        for(int i=1; i<n; i++)
        {
            int num1 = s[i] - '0';
            int num2 = s[i-1] - '0';
           if(num1 != 0)
               ans[i+1] = ans[i];
            
           if((10*num2 + num1) >= 10 && (10*num2 + num1)<=26)
               ans[i+1] += ans[i-1];
            
        }
        
        return ans[n];
    }