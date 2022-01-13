void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here  
        if(N==0)
            return;
        
        int count = 0;
        int del = 0;
        struct Node* temp = head;
        while(temp)
        {
            count++;
            if(count == M )
            {
               count = 0;
               del = 0;
               struct Node* temp1 = temp->next;
               while(temp1)
               {
                   del++;
                   if(del == N)
                   {
                       temp->next = temp1->next;
                       break;
                   }
                   temp1 = temp1->next;
               }
               if(!temp1)
                {
                    temp->next = NULL;
                    return;
                }
            }
            temp = temp->next;
        }
    }