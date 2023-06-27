//Hypothetical Queue Question
//Consider petrol pumps in a circular queue
//Intially, front and rear would be the first pump
//If balance petrol till now is positive, only rear would be increased
//However, if balance becomes negative, we're sure front would start at least from the next pump to rear
//Now, since we have space compexity constraint and cannot use a queue, also it would be better if we do it in once pass
//Keep a track of deficit till now, the moment balance becomes negative, that means from front to rear there would be deficit. (hence deficit, if there, would be continous)
//After loop finishes, if current balance is enough to nullify the deficit (that it will encounter AHEAD of it, if it were an actual circular queue), return front
//Else, tour cannot be completed. 

//TC: O(N)
//SC: O(1)

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int balance = 0;
       int deficit = 0;
       
       int balPetrol;
       int rear = 0;
       int front = 0;
       
       for(int i = 0; i < n; i++)
       {
           balPetrol = p[i].petrol - p[i].distance;
           
           balance += balPetrol;
           
           rear = i;
           
           if(balance < 0)
           {
               deficit += balance;
               front = rear + 1;
               balance = 0;
           }
           
           
       }
       
       if(balance + deficit >= 0)
            return front;
            
        else
            return -1;
    }
};
