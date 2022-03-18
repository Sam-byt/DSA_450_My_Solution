

void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    queue<int>newq;
    
    int n= (q.size()>>1);
    
    for(int i =0; i<n; i++){
        newq.push(q.front());
        q.pop();
    }
    
    while(!newq.empty())
    {
        q.push(newq.front());
        q.push(q.front());
        newq.pop();
        q.pop();
        
    }
    
}
