class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curColor = image[sr][sc];
        if (curColor == newColor) return image;
        
        fillHelper(image, sr, sc, newColor, curColor);
        return image;
    }
    void fillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int curColor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        } else {
            if (image[sr][sc] == curColor) {
                image[sr][sc] = newColor;
                fillHelper(image, sr, sc - 1, newColor, curColor);
                fillHelper(image, sr, sc + 1, newColor, curColor);
                fillHelper(image, sr - 1, sc, newColor, curColor);
                fillHelper(image, sr + 1, sc, newColor, curColor);
            }
        }
    }
};