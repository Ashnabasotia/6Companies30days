bool check (string temp, string str1)
    {
        string s = temp; 
        while(true)
        {
            int n1 = temp.size();
            int n2 = str1.size();
            if(n1 > n2)
                return false;
            if(temp == str1)
                return true;
            temp += s;    
        }
    }
    string gcdOfStrings(string str1, string str2) {
        
        int n1 = str1.size();
        int n2 = str2.size();
        
        bool choice = n1 < n2 ? true : false ;
        string temp;
        string ans;
        
        if(choice)
        {
            for(int i=1; i<=n1; i++)
            {
                temp = str1.substr(0,i);
                
                if(check(temp,str1) && check(temp,str2))
                {
                   ans = temp; 
                }
            }
        }
        else{
            for(int i=1; i<=n2; i++)
            {
                temp = str2.substr(0,i);
            
                if(check(temp,str2) && check(temp,str1))
                {
                    ans = temp;
                }
            }
        }
        
        return ans;
        
    }