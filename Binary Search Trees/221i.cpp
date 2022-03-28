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
    TreeNode * solve(vector<int> & preorder, int low, int high, int &i){
        
        if(i>=preorder.size())return nullptr;
        
        if(preorder[i]<low || preorder[i]>high)return nullptr;
        
        TreeNode * root = new TreeNode(preorder[i++]);
        
        root->left = solve(preorder,low,root->val,i);
        root->right = solve(preorder,root->val,high,i);
        
        return root;
        
        
        
        
    }
    
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        return solve(preorder,INT_MIN,INT_MAX,i);
        
        
        
        
    }
};
