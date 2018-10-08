class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() < 1) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        int max = nums[0];
        int secondMax = -1;
        int maxIndex = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                secondMax = max;
                max = nums[i];
                maxIndex = i;
            } else {
                if (nums[i] > secondMax) {
                    secondMax = nums[i];
                }
            }
        }
        if (max >= secondMax * 2) {
            return maxIndex;
        }
        return -1;
    }
};