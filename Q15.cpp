bool canPair(vector<int> nums, int k) {
        // Code here.
        
        vector <int> vec (k,0);
        int n = nums.size();
        
        if(n%2)
            return false;
        
        for(int i=0; i<n; i++)
        {
            vec[nums[i]%k]++;
        }
        
        if(vec[0]%2)
            return false;
        for(int i=1; i<=k/2; i++)
        {
            if(vec[i] != vec[k-i])
                return false;
        }
        return true;
    }