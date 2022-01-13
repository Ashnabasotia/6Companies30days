long long squaresInChessBoard(long long N) {
        // code here
        long long int ans = 0;
        
        ans = (N*(N+1)*(2*N+1))/6;
        return ans;
    }