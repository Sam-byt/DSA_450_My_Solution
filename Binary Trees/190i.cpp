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
    int height(TreeNode* p){
        return p?1+max(height(p->left),height(p->right)):0;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root){
            
            bool l = isBalanced(root->left);
            bool r = isBalanced(root->right);
            
            bool check = abs(height(root->left) - height(root->right)) <= 1;
            
            return l && r && check;
            
            
            
        }
        return true;
    }
};
