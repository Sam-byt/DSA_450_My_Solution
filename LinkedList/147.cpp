// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node * Reversal(Node *p)
{
    Node * q = nullptr, *r = nullptr;
    while(p)
    {
        r =q;
        q =p;
        p = p->next;
        
        q -> next =r;
    }
    
    return q;
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node*p = Reversal(head), *q = nullptr;
        int c =0,s =0;
        
        s = p->data + 1 + c;
        c = s/10;
        p->data = s%10;
        Node *first = p;
        q =p;
        p = p->next;
        
        
        while(p)
        {
            s = p->data + c;
            p -> data = s%10;
            c = s/10;
            q =p;
            p = p->next;
            
        }
        
        if(c>0)
        {
            Node *t = new Node(c);
            q -> next = t;
            q = t;
            // c = c/10;
            
        }
        
        return Reversal(first);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
