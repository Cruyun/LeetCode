class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int s = 0;
        while (i <= j) {
            s = max(s, (j - i) * min(height[i], height[j]));
            if (height[j] < height[i]) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};