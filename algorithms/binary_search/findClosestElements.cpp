/** 给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]

二分法：比较 mid 位置和 mid+k 位置分别与目标值的差距，以确定二分查找的范围，找到目标值最近的起始点，从而得出子数组

思路二： 不用二分查找
从首尾两头查找舍去，比较两头的数字与目标值的距离，如果一样就取小的值，直到剩余数组的长度是 size - k
**/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};