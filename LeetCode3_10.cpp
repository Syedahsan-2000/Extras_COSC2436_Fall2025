// Found question on Neetcode.io
//Requires LeetCode Premium
class Solution {
public:
    bool validTree(int numNodes, vector<vector<int>>& connections) {
        if(connections.size() != numNodes - 1) return false; // must have exactly n-1 edges
        
        vector<int> parent(numNodes);
        vector<int> height(numNodes, 0);
        for(int i = 0; i < numNodes; i++) parent[i] = i;
        
        function<int(int)> findRoot = [&](int node) -> int {
            if(parent[node] != node) parent[node] = findRoot(parent[node]);
            return parent[node];
        };
        
        auto unionNodes = [&](int a, int b) -> bool {
            int rootA = findRoot(a);
            int rootB = findRoot(b);
            if(rootA == rootB) return false; // cycle detected
            
            if(height[rootA] < height[rootB])
                parent[rootA] = rootB;
            else if(height[rootA] > height[rootB])
                parent[rootB] = rootA;
            else {
                parent[rootB] = rootA;
                height[rootA]++;
            }
            return true;
        };
        
        for(auto &conn : connections) {
            if(!unionNodes(conn[0], conn[1])) return false;
        }
        
        return true;
    }
};
