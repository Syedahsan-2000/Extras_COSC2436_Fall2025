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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool reverseOrder = false;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> currentLevel(size);
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();
                int pos = reverseOrder ? size - 1 - i : i;
                currentLevel[pos] = currentNode->val;

                if (currentNode->left) nodesQueue.push(currentNode->left);
                if (currentNode->right) nodesQueue.push(currentNode->right);
            }
            ans.push_back(currentLevel);
            reverseOrder = !reverseOrder;
        }

        return ans;
    }
};
