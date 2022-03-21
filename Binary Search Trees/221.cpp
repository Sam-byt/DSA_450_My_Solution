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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        stack<TreeNode *>s;
        int i = 1;
        TreeNode *root = new TreeNode(preorder[0]);
        int n = preorder.size();
        
        TreeNode *temp = root;
        
        while(i<n){
            
            TreeNode *t = new TreeNode(preorder[i]);
            
            if(preorder[i]<temp->val){
               
                s.push(temp);
                temp->left = t;
                temp = t;
                i++;
            }
            
            else{
                if(s.empty()){
                    temp->right = t;
                    temp = t;
                    i++;
                    
                }
                else{
                    if(preorder[i]<s.top()->val){
                        temp->right = t;
                        temp = t;
                        i++;
                    }
                    else{
                        temp = s.top();
                        s.pop();

                    }
                }
                
            }
            
            
        }
        
        return root;
        
    }
};
