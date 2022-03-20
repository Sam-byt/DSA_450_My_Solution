// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    
    void createMapping(int in[],unordered_map<int,int>&nodeToIndex,int n)
    {
        for(int i=0; i<n; i++)nodeToIndex[in[i]] = i;
    }
    
    
    
    Node* solve(int in[],int pre[],int &preorderindex,int inorderStart,int inorderEnd,int n, unordered_map<int,int>&nodeToIndex)
    {
        //base case
        if(preorderindex >= n || inorderStart > inorderEnd)return nullptr;
        
        int element = pre[preorderindex++];
        Node * root = new Node(element);
        int position = nodeToIndex[element];//finding index in map
        
        
        //recursion calls
        root->left = solve(in, pre, preorderindex, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, preorderindex, position+1, inorderEnd, n, nodeToIndex);
        
        return root;
        

        
        
    }
    
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int>nodeToIndex;
        //create nodetoindex map
        createMapping(in,nodeToIndex,n);//precomputation for finding position
        int preorderindex = 0;
        Node *ans = solve(in,pre,preorderindex,0,n-1,n,nodeToIndex);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
