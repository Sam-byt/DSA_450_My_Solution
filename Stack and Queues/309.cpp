void insertatbottom(stack<int>&s, int x)
{
    if(s.empty()){
		s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    insertatbottom(s,x);
    s.push(temp);
}


void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty())return;
    
    int temp = s.top();
    s.pop();
    
    reverseStack(s);
    insertatbottom(s,temp);
    
}
