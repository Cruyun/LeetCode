class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        int n = grid.size(); // row
        if (n == 0) return 0;
        int m = grid[0].size(); // col
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    num++;
                    BFS(i, j, grid);
                }
            }
        }
        return num;
    }
    void BFS(int i, int j, vector<vector<char>>& grid) {
        int n =  grid.size(); // row
        int m = grid[0].size(); // col
        
        grid[i][j] = '0';
        if (i != 0) {
            if (grid[i - 1][j] == '1') BFS(i - 1, j, grid);
        }
        if (i != n - 1) {
            if (grid[i + 1][j] == '1') BFS(i + 1, j, grid);
        }
        if (j != 0) {
            if (grid[i][j - 1] == '1') BFS(i, j - 1, grid);
        }
        if (j != m - 1) {
            if (grid[i][j + 1] == '1') BFS(i, j + 1, grid);
        }
    }
};