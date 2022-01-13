int getIndex (char c)
    {
        if(c == '!')
            return 0;
        else if(c == '#')
            return 1;
        else if (c == '$')
            return 2;
        else if (c == '%')
            return 3;
        else if (c == '&')
            return 4;
        else if (c == '*')
            return 5;
        else if (c == '@')
            return 6;
        else if (c == '^')
            return 7;
        else if (c == '~')
            return 8;
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    string s = "!#$%&*@^~";
	    
	    vector<int>bolts_v;
	    vector<int>nuts_v;
	    
	    for(int i=0; i<n; i++)
	    {
	        bolts_v.push_back(getIndex(bolts[i]));
	        nuts_v.push_back(getIndex(nuts[i]));
	    }
	    
	    sort(bolts_v.begin(),bolts_v.end());
	    sort(nuts_v.begin(),nuts_v.end());
	    
	    for(int i=0; i<n; i++)
	    {
	        bolts[i] = s[bolts_v[i]];
	        nuts[i]  = s[nuts_v[i]];
	    }
	    
	}