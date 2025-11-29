//Clone Graph along with a helper function dfsClone
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* original) {
        if (!original) return nullptr;

        unordered_map<Node*, Node*> visited;
        return dfsClone(original, visited);
    }

private:
    Node* dfsClone(Node* currNode, unordered_map<Node*, Node*>& clonedMap) {
        if (clonedMap.find(currNode) != clonedMap.end()) {
            return clonedMap[currNode];
        }

        Node* nodeCopy = new Node(currNode->val);
        clonedMap[currNode] = nodeCopy;

        for (Node* adjNode : currNode->neighbors) {
            nodeCopy->neighbors.push_back(dfsClone(adjNode, clonedMap));
        }

        return nodeCopy;
    }
};
