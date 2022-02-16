// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
class Solution
{
    private:
    bool isLoop(Node * &p)
    {
        Node * q = p;
        
        do
        {
            q = q->next;
            p = p->next;
            
            
            p = p?p->next : nullptr;
            
            
        }while(p && p!=q);
        
        return p!= nullptr;
    }
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node * p = head, *q = nullptr;
        // code here
        // just remove the loop without losing any nodes
        if(!isLoop(p))return;
        else{
            
            q = p;
            int len =0;
            do{
                len++;
                p = p->next;
                
            }while(q!=p);
            
            for(int i=0;i<len;i++){
                p = q;
                q = q->next;
            }
            
            while(head!=q){
                
                p = q;
                head = head->next;
                q = q->next;
            }
            
            p -> next = nullptr;
            
            
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends
