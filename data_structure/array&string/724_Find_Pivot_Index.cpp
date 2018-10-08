class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        int i;
        int sum = 0;
        int left = 0;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        for (i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left = 0;
            } else {
                left += nums[i - 1];
            }
            int right = sum - left - nums[i];
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};