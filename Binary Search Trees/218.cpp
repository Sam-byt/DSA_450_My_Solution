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

#define ll long long
class Solution {

private:
    
    bool isBST(TreeNode *root, ll low,ll high)
    {
        if(!root)return true;
        
        if(root->val>low && root->val<high){
            
            bool lans = isBST(root->left,low,root->val);
            bool rans = isBST(root->right,root->val,high);
            
            return lans && rans;
            
        }
        
        else return false;
    }
    

public:
    bool isValidBST(TreeNode* root) {
        
        return isBST(root,INT64_MIN,INT64_MAX);
    }
};
