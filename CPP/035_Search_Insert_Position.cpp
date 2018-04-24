class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target) {
                if (i == 0) {
                    index = 0;
                } else if (nums[i - 1] < target) {
                    index = i;
                }
            } else if (nums[i] == target) {
                index = i;
            }
        }
        if (nums[nums.size() - 1] < target)
            index = nums.size();
        return index;
    }
};