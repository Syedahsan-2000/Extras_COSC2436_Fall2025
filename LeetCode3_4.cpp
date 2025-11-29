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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        function<int(TreeNode*)> getHeight = [&](TreeNode* current) -> int {
            if (!current) return 0;
            int leftHeight = getHeight(current->left);
            int rightHeight = getHeight(current->right);
            maxDiameter = max(maxDiameter, leftHeight + rightHeight);
            return 1 + max(leftHeight, rightHeight);
        };
        getHeight(root);
        return maxDiameter;
    }
};
