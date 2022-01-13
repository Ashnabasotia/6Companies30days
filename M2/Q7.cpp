string FirstNonRepeating(string A){
		    // Code here
		    vector<int> alpha(26,0);
		    int n = A.size();
		    string ans="";
		    string temp="";
		    
		    for (int i=0; i<n; i++)
		    {
		        int flag = false;
		        alpha[A[i]-'a']++;
		        if(alpha[A[i]-'a'] == 1)
		            temp = temp + A[i];
		        
		        for(int j=0; j<temp.size(); j++)
		        {
		            if(alpha[temp[j]-'a'] == 1)
		            {
		                ans += temp[j];
		                flag = true;
		                break;
		            }
		        }
		        
		        if(!flag)
		            ans += '#';
		    }
		    return ans;
		}