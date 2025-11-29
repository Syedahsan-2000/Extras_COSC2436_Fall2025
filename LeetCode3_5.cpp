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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> valToIndex;
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }

        function<TreeNode*(int,int,int,int)> construct = [&](int inLeft, int inRight, int postLeft, int postRight) -> TreeNode* {
            if (inLeft > inRight || postLeft > postRight) return nullptr;
            int rootValue = postorder[postRight];
            TreeNode* node = new TreeNode(rootValue);
            int indexInInorder = valToIndex[rootValue];
            int leftTreeSize = indexInInorder - inLeft;
            node->left = construct(inLeft, indexInInorder - 1, postLeft, postLeft + leftTreeSize - 1);
            node->right = construct(indexInInorder + 1, inRight, postLeft + leftTreeSize, postRight - 1);
            return node;
        };

        return construct(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
