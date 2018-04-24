class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        int i, j;
        
        for (i = 0; strs.size() > 0; common += strs[0][i], i++) {
            for (j = 0; j < strs.size(); j++) {
                if (strs[j].size() <= i || (j > 0 && strs[j - 1][i] != strs[j][i])) {
                    return common;
                }
            }
        }
        return common;
    }
};