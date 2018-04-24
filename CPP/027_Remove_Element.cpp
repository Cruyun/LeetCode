class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;
        while (i <= j && nums.size() != 0) {
            if (nums[i] == val) {
                ++count;
                nums[i] = nums[j];
                --j;
            } else {
                ++i;
            }
        }
        return nums.size() - count;
    }
};