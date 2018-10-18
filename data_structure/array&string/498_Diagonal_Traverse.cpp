class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        
        int i = 0, j = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int len = m * n;

        for (int k = 0; k < len; k++) {
            result.push_back(matrix[i][j]);
            if ((i + j) % 2 == 0) {
                if(j == n - 1) {
                    i++;
                } else if (i == 0) {
                    j++;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == m - 1) {
                    j++;
                } else if (j == 0) {
                    i++;
                } else {
                    j--;
                    i++;
                }
            }
        }
        return result;
    }
};