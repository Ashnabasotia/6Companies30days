vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        set< vector<int> > ans;
        vector<vector<int> > f_ans;
        sort(arr.begin(),arr.end());
        //Calculate frequency
        
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int begin = j+1;
                int end = n-1;
                while(begin < end)
                {
                    if(arr[i]+arr[j]+arr[begin]+arr[end] == k)
                        {
                            ans.insert({arr[i],arr[j],arr[begin],arr[end]});
                            begin++;
                        }
                    else if(arr[i]+arr[j]+arr[begin]+arr[end] < k)
                        begin++;
                    else
                        end--;
                    
                }
            }
        }
        for(auto it=ans.begin(); it != ans.end(); it++) 
            f_ans.push_back(*it);
        return f_ans;
    }