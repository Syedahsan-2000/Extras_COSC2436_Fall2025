// isSymmteric tree using a helper function
// called Mirror
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
    
    bool Mirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;  
        if (t1 == nullptr || t2 == nullptr) return false; 
        if (t1->val != t2->val) return false;           
        
        
        return Mirror(t1->left, t2->right) && Mirror(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; 
        return Mirror(root->left, root->right);
    }
};
