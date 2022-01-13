vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector <int> ans;
        deque<int> Qi(k);
        int i;
        for(i=0; i<k; ++i)
        {
            // For every element, the previous smaller elements are
            //useless so remove them from Qi
            while((!Qi.empty()) && arr[i] >= arr[Qi.back()])
                Qi.pop_back();
            Qi.push_back(i);
        }
        
        
        for(; i<n; ++i)
        {
            ans.push_back(arr[Qi.front()]);
            while((!Qi.empty()) && Qi.front() <= i-k)
                Qi.pop_front();
                
            while((!Qi.empty()) && arr[i] >= arr[Qi.back()])
                Qi.pop_back();
            Qi.push_back(i);
        }
        ans.push_back(arr[Qi.front()]);
       return ans; 
    }