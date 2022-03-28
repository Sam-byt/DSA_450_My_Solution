/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>*root,vector<int>&inorder){
	if(root){
        solve(root->left,inorder);
        inorder.push_back(root->data);
        solve(root->right,inorder);
    }

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int>inorder;
    solve(root,inorder);
    TreeNode<int>*first = nullptr, *r = nullptr;
    bool flag = true;
    for(auto i:inorder){
        if(flag){
            TreeNode<int> *temp = new TreeNode<int>(i);
            first = temp;
            r =  temp;
            flag = false;
        }
        else{
            TreeNode<int> *temp = new TreeNode<int>(i);
            r -> right = temp;
            r =  temp;
        }
    }
    return first;
    
    
}
