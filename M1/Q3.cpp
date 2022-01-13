    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
      
      long long p = 1;
      int res = 0;
      int start,end;
      for(start = 0,  end=0; end<n; end++)
      {
          p*=a[end];
          while(start < end && p >= k )
          {
              p /= a[start++];
          }
          
          if(p < k)
          {
              int len = 1 + (end-start);
              res += len;
          }
      }
      
      return res;
      
    }