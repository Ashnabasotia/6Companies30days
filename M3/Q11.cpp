string binary (int n)
{
    string str="";
    
    while(n!=0)
    {
        int rem = n%2;
        str = (rem? '1': '0') + str;
        n = n/2;
    }
    return str;
}
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1; i<=N; i++)
	{
	    ans.push_back(binary(i));
	}
	return ans;
	
}