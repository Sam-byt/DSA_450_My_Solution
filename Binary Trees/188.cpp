// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node *, int>> q;
        unordered_map<int, vector<int>> umap;

        int hd = 0, hdmax = INT_MIN, hdmin = INT_MAX;

        q.push(make_pair(root, hd));

        umap[hd].push_back(root->data);

        pair<Node *, int> p;

        if (hd > hdmax)
            hdmax = hd;

        if (hd < hdmin)
            hdmin = hd;

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            if (p.first->left)
            {
                hd = p.second - 1;
                if (hd > hdmax)
                    hdmax = hd;

                if (hd < hdmin)
                    hdmin = hd;

                q.push(make_pair(p.first->left, hd));
                umap[hd].push_back(p.first->left->data);
            }


            if (p.first->right)
            {
                hd = p.second + 1;
                if (hd > hdmax)
                    hdmax = hd;

                if (hd < hdmin)
                    hdmin = hd;

                q.push(make_pair(p.first->right, hd));
                umap[hd].push_back(p.first->right->data);
            }
        }

        for(int i = hdmin; i <= hdmax; i++)
        {
            if(umap[i].size()>0)
                ans.push_back(*(umap[i].end()-1));
            
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


  // } Driver Code Ends
