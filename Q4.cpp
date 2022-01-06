string encode(string src)
{     
  //Your code here 
  string temp = "";
  int n = src.size();
  int count = 1;
  for(int i=0; i<n-1; i++)
  {
      if(src[i] == src[i+1])
        {
            count++;
        }
        else
        {
            temp += src[i];
            string num = to_string(count);
            temp += num;
            count = 1;
        }
  }
  
   return src[n-1] == src[n-2] ? temp + src[n-1] + to_string(count) : temp + src[n-1] + "1";
  
 }