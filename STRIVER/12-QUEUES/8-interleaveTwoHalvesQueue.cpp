//TC: O(N)
//SC: O(N/2);
void interLeaveQueue(queue < int > & q) {
    queue<int> qtemp;
    int length = q.size();
    
    int count = 0;
    while(count < (length / 2))
        {
            qtemp.push(q.front());
            q.pop();
            count++;
        }
    
    while(!qtemp.empty())
    {
        q.push(qtemp.front());
        qtemp.pop();
        q.push(q.front());
        q.pop();
    }
}
