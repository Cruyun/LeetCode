class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        unordered_set<int> n2;
        int i, j;
        vector<int> res;
        
        for (i = 0; i < nums1.size(); i++) {
            if (n1.count(nums1[i]) == 0) {
                n1.insert(nums1[i]);
            }
        }
        for (j = 0; j < nums2.size(); j++) {
            if (n2.count(nums2[j]) == 0) {
                n2.insert(nums2[j]);
            }
        }
        for (auto k = n1.begin(); k != n1.end(); ++k) {
            if (n2.count(*k) > 0) {
                res.push_back(*k);
            }
        }
        return res;
    }
};