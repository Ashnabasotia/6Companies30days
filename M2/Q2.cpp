 int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int ans = 0;
        int inc = 1;
        int dec = 1;
        for(int i=1; i<n;)
        {
            //Longest increasing
            while(i<n && arr[i] == arr[i-1])
            {
                i++;
            }
            while(i<n && arr[i] > arr[i-1] )
            {
                inc++;
                i++;
            }
            while(i<n && arr[i] < arr[i-1])
            {
                dec++;
                i++;
            }
            if(inc != 1 && dec!=1)
            {
                ans= max(ans, (inc+dec-1));
            }
            inc=1;
            dec=1;
        }
        return ans;
    }