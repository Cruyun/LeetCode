/**
 二分法
rotated sorted array是至少有一侧是排好序的

 如果target比A[mid]值要小
  如果A[mid]右边有序（A[mid]<A[high])
    那么target肯定不在右边（target比右边的都得小），在左边找
  如果A[mid]左边有序
    那么比较target和A[low]，如果target比A[low]还要小，证明target不在这一区，去右边找；反之，左边找。
如果target比A[mid]值要大
  如果A[mid]左边有序（A[mid]>A[low]）
    那么target肯定不在左边（target比左边的都得大），在右边找 
  如果A[mid]右边有序
    那么比较target和A[high]，如果target比A[high]还要大，证明target不在这一区，去左边找；反之，右边找。
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.size() == 0) return -1;
      int low = 0;
      int high = nums.size() - 1;
      while (low <= high) {
        int mid = ( low + high ) / 2;
        if (target < nums[mid]) {
          // 右边有序，去左边找
          if (nums[mid] < nums[high]) {
            high = mid - 1;
          } else if (target < nums[low]) { // 目标值比左边最小的还小，说明不在左边，去右边找
            low = mid + 1;
          } else { // 右边无序，目标值可能在左边的序列中
            high = mid - 1;
          }
        } else if (target > nums[mid]) {
          // 左边有序
          if (nums[low] < nums[mid]) {
            low = mid + 1;
          } else if (target > nums[high]) {
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        } else {
          return mid;
        }
      }
      
      return -1;
    }
};