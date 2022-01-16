 public:
    //Function to find list of all words possible by pressing given numbers.
    string helper (int n)
    {
        if(n == 2)
            return "abc";
        else if(n == 3)
            return "def";
        else if(n == 4)
            return "ghi";
        else if(n == 5)
            return "jkl";
        else if(n == 6)
            return "mno";
        else if (n == 7)
            return "pqrs";
        else if(n == 8)
            return "tuv";
        else 
            return "wxyz";
    }
    void possibleWordsHelper(int a[], int n,vector<string>& ans ,string str)
    {
        if(str.size() == n)
        {
            ans.push_back(str);
            return;
        }
        string temp = helper(a[str.size()]);
        for(int k=0; k<temp.size(); k++)
        {
            possibleWordsHelper(a,n,ans,str+temp[k]);
        }
        return;
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector <string> ans;
        possibleWordsHelper(a,N,ans,"");
        return ans;
    }