/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "";
        string result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* current = nodeQueue.front();
            nodeQueue.pop();
            if (current) {
                result += to_string(current->val) + ",";
                nodeQueue.push(current->left);
                nodeQueue.push(current->right);
            } else {
                result += "N,";
            }
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* rootNode = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(rootNode);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            if (!getline(ss, val, ',')) break;
            if (val != "N") {
                parent->left = new TreeNode(stoi(val));
                q.push(parent->left);
            }

            if (!getline(ss, val, ',')) break;
            if (val != "N") {
                parent->right = new TreeNode(stoi(val));
                q.push(parent->right);
            }
        }
        return rootNode;
    }
};
