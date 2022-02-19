/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

*****************************************************************/

bool findPair(Node* head, int k)
{
    // Write your code here.
    Node * first = head, *second = head;
    while(second->next)second = second -> next;
    
    while(first != second && second->next != first)
    {
        if(first -> data + second-> data < k)first = first -> next;
        else if(first -> data + second -> data > k )second = second -> prev;
        else return true;
    }
    
    return false;
        
}

