      string createString (string str, int num )
    {
        string temp = "";
        for(int i=0; i<num; i++)
        {
            temp += str;
        }
        return temp;
    }
    string decodeString(string s) {
        int n = s.size();
        
        string number="";
        string str   ="";
        string bracket="";
        
        stack<string> q;
        q.push("");
        for(int i=0; i<n; )
        {
           //forming the string
           if(s[i] >= 'a' && s[i] <= 'z')
           {
                while(i<n && (s[i] >= 'a' && s[i] <= 'z'))
                {
                    str += s[i++];
                }
                string temp = q.top();
                if(temp == "[")
                    q.push(str);
                else{
                    q.pop();
                    temp = temp + str;
                    q.push(temp);
                }
                str="";
           }
           //forming the number
           else if (s[i]>='0' && s[i]<='9')
           {
                while(i<n && s[i]>='0' && s[i]<='9')
                {
                    number += s[i++];
                }
                
                q.push(number);
                number="";
           }
           //Now we need to push '['
           else if (s[i] == '[')
           {
               bracket += '[';
               q.push(bracket);
               i++;
               bracket="";
           }
           else{
              str = q.top();
              q.pop();
              bracket = q.top();
              q.pop();
              number = q.top();
              q.pop();
              string newString = createString(str,stoi(number));
              string temp = q.top();
               if(temp == "[")
                   q.push(newString);
               else
               {
                   q.pop();
                   temp = temp + newString;
                   q.push(temp);
               }     
              i++;
              str="";
              bracket="";
              number="";
           }
        }
        
        string ans = "";
        
        while(!q.empty())
        {
            string res =  q.top() ;
            ans = res + ans;
            q.pop();
        }
        
        return ans;
        
    }