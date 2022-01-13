int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        // if(L1[0] == R1[0] || L1[1] == R1[1] || L2[0] == R2[0] || L2[1] == R2[1])
        //     return 0;
            
        int left1 = L1[0] < R1[0] ? L1[0] : R1[0];
        int right1 = L1[0] > R1[0] ? L1[0] : R1[0];
        
        int left2  = L2[0] < R2[0] ? L2[0] : R2[0];
        int right2 = L2[0] > R2[0] ? L2[0] : R2[0];
        
        int lower1 = L1[1] < R1[1] ? L1[1] : R1[1];
        int upper1 = L1[1] > R1[1] ? L1[1] : R1[1];
        
        int lower2 = L2[1] < R2[1] ? L2[1] : R2[1];
        int upper2 = L2[1] > R2[1] ? L2[1] : R2[1];
        
        
        // Rectangle lies to the left side
        if(left2 > right1 || left1 > right2)
            return 0;
        
        //Rectangle lies on top
        if(lower1 > upper2 || lower2 > upper1)
            return 0;
        
        return 1;
        
    }