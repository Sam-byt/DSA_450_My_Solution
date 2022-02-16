// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    private:
    
    Node * Reversal(Node *p)
    {
        Node* q = nullptr, *r = nullptr;
        
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        
        return q;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        first = Reversal(first);
        second = Reversal(second);
        
        int temp,sum,carry=0;
        
        temp = first->data + second->data + carry;
        sum = temp %10;
        carry = temp/10;
            
        first = first->next;
        second = second->next;
        
        
        Node *head = new Node(sum);
        Node *t = nullptr, *r =nullptr;
        
        t = head;
        
            
        
        while(first && second)
        {
            temp = first->data + second->data + carry;
            sum = temp %10;
            carry = temp/10;
            
            r = new Node(sum);
            t->next = r;
            t = r;
            
            
            first = first->next;
            second = second->next;
        }
        
        while(first)
        {
            temp = first->data + carry;
            sum = temp %10;
            carry = temp/10;
            
            r = new Node(sum);
            t->next = r;
            t = r;
            
            
            first = first->next;
        }
        
        while(second)
        {
            temp = second->data + carry;
            sum = temp %10;
            carry = temp/10;
            
            r = new Node(sum);
            t->next = r;
            t = r;
            
            
            second = second->next;
            
        }
        
        while(carry)
        {
            sum = carry %10;
            carry/=10;
            
            r = new Node(sum);
            t->next = r;
            t = r;
            
        }
        
        return Reversal(head);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
