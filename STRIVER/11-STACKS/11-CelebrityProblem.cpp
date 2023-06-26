//Brute
//For each element, check if this person knows anyone or anyone knows this person
//0 to i -> 0 to j
//TC: O(N^2)
//SC: O(1)

//OPTIMAL
//STACK
//We know that if knows(i, j) , then i cannot be a celebrity for sure. Have to check j with others. Since we know only one celebrity can exist, keep checking and eliminating others till we are left with only one element as the celebrity. 
//This element can be our potential celebrity. Loop through persons and check if this person is a celebrity. 
//TC: O(N)
//SC: O(N)

int findCelebrity(int n) {
    // Write your code here.
    if(n <= 1)
        return -1;


    stack<int> s;
    
    for(int i = 0; i < n; i++) 
        s.push(i);


    int a, b;
    
    while(s.size() > 1)
    {
        a = s.top();
        s.pop();


        if(s.empty())
            break;


        b = s.top();
        s.pop();


        //if a know b, then a can never be a celebrity. b might be
        if(knows(a, b))
            s.push(b);


        else
            s.push(a);
    }
    int candidate = s.top();


    for(int i = 0; i < n; i++)
    {
        if(candidate != i)
        {
            if(knows(candidate, i))
                return -1;


            if(!knows(i, candidate))
                return -1;
        }
    }


    return candidate;
}
