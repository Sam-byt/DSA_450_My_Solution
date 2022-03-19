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

typedef pair<bool,int> pi;

class Solution {

private:
    pi solve(TreeNode *root){
        
        if(root){
            
            pi l = solve(root->left);
            pi r = solve(root->right);
            
            bool check = abs(l.second - r.second)<=1;
            
            return {l.first && r.first && check, 1 + max(l.second,r.second) };
            
        }
        return {true,0};
        
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};
