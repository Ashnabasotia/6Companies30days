vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n);
       for(int i=1; i<n; i++)
       {
           if(price[i-1] <= price[i])
            {    
                int j=i-1;
                int counter = 1;
                while(j>=0 && price[j]<=price[i])
                {
                    counter += ans[j] ;
                    j-=ans[j];
                }
                ans[i] = counter;
            }
       }
       return ans;
    }