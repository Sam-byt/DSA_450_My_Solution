/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
TreeNode<int>* solve(int s, int e, vector<int>v){
    if(s>e)return nullptr;
    
    int mid = s + (e-s)/2;
    
    TreeNode<int> *root = new TreeNode<int>(v[mid]);
    
    root->left = solve(s,mid -1,v);
    root->right = solve(mid + 1,e,v);
    
    return root;
}

void inorder(TreeNode<int> *root, vector<int> &v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}

vector<int> mergeSortedArray(vector<int>v1, vector<int> v2){
    
    vector<int> v;
    
    int i = 0, j = 0;
    
    while(i<v1.size() && j<v2.size())  
        v1[i]<v2[j]?v.push_back(v1[i++]):v.push_back(v2[j++]);
    
    while(i<v1.size())
        v.push_back(v1[i++]);
    
    while(j<v2.size())
        v.push_back(v2[j++]);
    
    return v;
    
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int>v1;
    vector<int>v2;
    inorder(root1,v1);
    inorder(root2,v2);
    
    vector<int>v = mergeSortedArray(v1,v2);
    
    return solve(0,v.size()-1,v);
}
