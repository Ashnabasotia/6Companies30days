 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        for (int i=0; i<n; i++)
        {
            string cpy = strs[i];
            sort(cpy.begin(),cpy.end());
            if(mp.find(cpy) == mp.end())
            {
                mp.insert({cpy,vector<string>()});
            }
            mp[cpy].push_back(strs[i]);
        }
        vector <vector<string>> ans;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }