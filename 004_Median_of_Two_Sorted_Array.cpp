class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i(0), j(0);
        vector<int> arr;

        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        if (i < size1) {
            while (i < size1) {
                arr.push_back(nums1[i]);
                i++;
            }
        } else {
            while (j < size2) {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        double mid;
        int loc;

        if ((size1 + size2) % 2 == 0) {
            loc = (size1 + size2) / 2;
            mid = (arr[loc - 1] + arr[loc]) / 2.0;
        } else {
            loc = ( size1 + size2 - 1 ) / 2;
            mid = arr[loc];
        }
        return mid;
    }
};