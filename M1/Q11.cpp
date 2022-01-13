int *findTwoElement(int *arr, int n) {
        // code here
        int i;
        int * ans = (int*)malloc(2*sizeof(int));
        for(i=0; i<n; i++)
        {
            if(arr[abs(arr[i])-1] > 0)
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            else
                ans[0] = abs(arr[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > 0)
                ans[1] = i+1;
        }
        
        return ans;
    }