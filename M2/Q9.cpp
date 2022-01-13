void make_zero(vector<int>& nums)
    {
        for(int i=0; i<10; i++)
            nums[i] = 0;
    }
    int isValid(vector<vector<int>> mat){
        // code here
        //Row wise check
        bool flag_r = true;
        bool flag_c = true;
        bool flag_g = true;
        vector<int>nums(10,0);
        for(int i=0; i<9;i++)
        {
            
            for(int j=0;j<9;j++)
            {
                nums[mat[i][j]]++;
                if(mat[i][j] && nums[mat[i][j]] > 1)
                {
                    flag_r = false;
                    break;
                }
                    
            }
            make_zero(nums);
            if(!flag_r)
                break;
        }
        
       
        
        //Column-Wise
        for(int i=0; i<9; i++)
        {
            for(int j=0;j<9;j++)
            {
                nums[mat[j][i]]++;
                if(mat[j][i] && nums[mat[j][i]] > 1)
                {
                    flag_c = false;
                    break;
                }
            }
            make_zero(nums);
            if(!flag_c)
                break;
        }
        
       
       //Smaller Grid 
        for(int i=0; i<9; i+=3)
           {
               for(int j=0; j<9; j+=3)
               {
                   for(int k=0; k<3; k++)
                   {
                       for(int p=0; p<3; p++)
                       {
                           nums[mat[i+k][j+p]]++;
                           if(mat[i+k][j+p] && nums[mat[i+k][j+p]] > 1)
                           {
                               flag_g = false;
                               break;
                           }
                       }
                       if(!flag_g)
                        break;
                   }
                   make_zero(nums);
                    if(!flag_g)
                        break;
               }
               if(!flag_g)
                break;
           }
           
        if(flag_r && flag_c && flag_g)
            return 1;
        else
            return 0;
    
           
       }
