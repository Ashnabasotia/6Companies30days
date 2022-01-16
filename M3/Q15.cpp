void helper (int i, vector<bool>& visited, stack<int>& Stack,map<int,vector<int>>& mp)
    {
        visited[i] = true;
        int n = mp[i].size();
        for(int x=0; x<n; x++)
        {
            if(!visited[mp[i][x]])
                helper(mp[i][x],visited,Stack,mp);
        }
        
        Stack.push(i);
    }
    void topologicalSort (string& ans, map<int,vector<int>>& mp, int K)
    {
        stack<int> Stack;
        vector<bool> visited(K,false);
        
        for(int i=0; i<K; i++)
            {
                if(visited[i] == false)
                    helper(i,visited,Stack,mp);
            }
        while(Stack.empty() == false)
        {
            ans += (char)('a' + Stack.top());
            Stack.pop();
        }
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        int n = N;
        map<int,vector<int>> mp;
       for(int i=0; i<K; i++)
            mp.insert({i, vector<int>()});
       
       //Process all adjacent pair of words and create a graph
       for(int i=0; i<n-1; i++)
       {
           string word1 = dict[i];
           string word2 = dict[i+1];
           for(int j=0; j< min(word1.length(),word2.length()); j++)
           {
               if(word1[j] != word2[j])
               {
                   mp[word1[j]-'a'].push_back(word2[j]-'a');
                   break;
               }
           }
       }
       string ans="";
       topologicalSort(ans,mp,K);
       return ans;
    }