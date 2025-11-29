// Number of Islands problem
class Solution {
public:
    void explore(vector<vector<char>>& map, int row, int col) {
        int totalRows = map.size();
        int totalCols = map[0].size();
        if (row < 0 || col < 0 || row >= totalRows || col >= totalCols || map[row][col] == '0') return;
        map[row][col] = '0';
        explore(map, row + 1, col);
        explore(map, row - 1, col);
        explore(map, row, col + 1);
        explore(map, row, col - 1);
    }

    int numIslands(vector<vector<char>>& map) {
        int count = 0;
        int totalRows = map.size();
        if (totalRows == 0) return 0;
        int totalCols = map[0].size();
        for (int r = 0; r < totalRows; r++) {
            for (int c = 0; c < totalCols; c++) {
                if (map[r][c] == '1') {
                    count++;
                    explore(map, r, c);
                }
            }
        }
        return count;
    }
};
