/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/
int countpairs(DLLNode* first, DLLNode * second, int value)
{
    int cnt =0;
    
    while(first && second && first != second && second->next != first)
    {
        if(first->data + second->data < value)first = first->next;
        else if(first->data + second->data > value)second = second->prev;
        else{
            cnt++;
            first = first->next;
            second = second -> prev;
        }
    }
    
    return cnt;
    
}


int countTriplets(DLLNode* head, int x)
{
    // WRITE YOUR CODE HERE
    DLLNode * first = head, * last =  head, * curr = head ;
    
    while(last->next)last = last -> next;
    
    int cnt = 0;
    
    while(curr)
    {
        first = curr->next;
        cnt += countpairs(first,last,x - curr->data);
        curr = curr->next;
    }
    
    return cnt;
    
    
    
    
    
}  
