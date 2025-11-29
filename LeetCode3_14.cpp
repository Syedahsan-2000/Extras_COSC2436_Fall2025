//ShortestPathBinary matrix problem
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& gridMap) {
        int size = gridMap.size();
        if(gridMap[0][0] != 0 || gridMap[size-1][size-1] != 0) return -1;

        vector<pair<int,int>> moves = {
            {0,1}, {1,0}, {0,-1}, {-1,0},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({0,0});
        gridMap[0][0] = 1; // store distance

        while(!bfsQueue.empty()) {
            auto [r, c] = bfsQueue.front();
            int pathLen = gridMap[r][c];
            bfsQueue.pop();

            if(r == size-1 && c == size-1) return pathLen;

            for(auto [dr, dc] : moves) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nr < size && nc >= 0 && nc < size && gridMap[nr][nc] == 0) {
                    gridMap[nr][nc] = pathLen + 1;
                    bfsQueue.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
