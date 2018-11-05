class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        int m = matrix[0].size(); // col num
        int n = matrix.size(); // row
        int a = 0, b = 0, c = n - 1, d = m - 1;
        int count = 0;
        int i = 0; // row flag
        int j = 0; // col flag
        
        while (count < n * m) {
            // right
            while (j <= d && count < n * m) {
                res.push_back(matrix[i][j]);
                j++;
                count++;
            }
            // down
            j--;
            i++;
            while (i <= c && count < n * m) {
                res.push_back(matrix[i][j]);
                i++;
                count++;
            }
            // left
            i--;
            j--;
            while (j >= b && count < n * m) {
                res.push_back(matrix[i][j]);
                j--;
                count++;
            }
            j++;
            i--;
            // up
            while (i > a && count < n * m) {
                res.push_back(matrix[i][j]);
                i--;
                count++;
            }
            a++;
            b++;
            c--;
            d--;
            i = a;
            j = b;
        }
        return res;
    }
};