 string colName (long long int n)
    {
        // your code here
        if(n >=1  &&  n<=26 )
        {
           string temp = "A";
           temp[0] = temp[0] + (n-1);
           return temp;
        }
            
        
        if(!(n%26))
        {
            string ans = colName(n-1);
            int len = ans.size();
            return ans.substr(0,len-1) + 'Z';
        }
        return colName(n/26) + colName(n%26);
    }