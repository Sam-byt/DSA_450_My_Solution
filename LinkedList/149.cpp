// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* p, Node* q)
{
    // Your Code Here
    
    Node * first = nullptr,*r =nullptr;
    bool flag = true;
    
    while(p && q)
    {
        if(p->data < q ->data)p= p->next;
        
        else if(p->data > q->data)q = q->next;
        
        else{
            if(flag){
            Node *t = new Node(p->data);
            r = t;
            first = t;
            flag = false;
            }
            
            else{
                Node *t = new Node(p->data);
                r -> next = t;
                r = t;
                
            }
            
            p = p->next;
            q = q-> next;
            
        }
        
        
    }
    
    return first;
}
