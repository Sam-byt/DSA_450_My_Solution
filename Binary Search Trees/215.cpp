/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
private:
    int inpre(TreeNode *root)
    {
        while(root->right)root = root->right;
        
        return root->val;
    }
    
    int inSuc(TreeNode *root){
        
        while(root->left)root = root->left;
        
        return root->val;
        
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return root;
        
        if(key == root->val){
            
            //leaf
            if(!(root->left || root->right)){
                delete root;
                return nullptr;
            }
            
            else if(root->left && !root->right){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            
            else if(!root->left && root->right){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            
            else{
                
                //Inorder Predecessor
                int pred = inpre(root->left);
                root->val = pred;
                root->left = deleteNode(root->left,pred);
                return root;
                
                
                
                
                //Inorder Sucessor
                
                
                
                
            }
            
            
        }
        
        
        
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        
        else{
            root->right = deleteNode(root->right,key);
            return root;
        }
        
    }
};
