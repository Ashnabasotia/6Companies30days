ull Min (ull n1, ull n2, ull n3)
	{
	    ull a1 = n1 < n2 ? n1 : n2;
	    return n3 < a1 ? n3 : a1;
	   
	}
	ull getNthUglyNo(int n) {
	    // code here
	    if(n==1)
	        return 1;
	    
	    vector <ull> mulTwo;
	    vector <ull> mulThree;
	    vector <ull> mulFive;
	    
	    mulTwo.push_back(1);
	    mulThree.push_back(1);
	    mulFive.push_back(1);
	    
	    int i2=0,i3=0,i5=0;
	    ull nextUgly;
	    
	    for(int i=1; i<=n; i++)
	    {
	        nextUgly = Min(mulTwo[i2],mulThree[i3],mulFive[i5]);
	        
	        if(nextUgly == mulTwo[i2])
	        {
	            i2++;
	            
	        }
	        
	        if(nextUgly == mulThree[i3])
	        {
	            i3++;
	           
	        }
	        
	        if(nextUgly == mulFive[i5])
	        {
	            i5++;
	           
	        }
	        mulTwo.push_back(nextUgly*2);
	        mulThree.push_back(nextUgly*3);
	        mulFive.push_back(nextUgly*5);
	        
	    }
	    
	    return nextUgly;
	    
	}