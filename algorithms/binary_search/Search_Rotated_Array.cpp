class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;
            
            mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[left] > nums[mid] ) {
                if (target > nums[mid] && nums[left] > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target < nums[mid] && nums[left] < target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;        
    }                 
};