class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[255];
        int left = 0;
        int result = 0;
        memset(hash, -1, sizeof hash);
        
        for (int i = 0; i < s.length(); i++) {
            if (hash[s[i]] >= left)
                left = hash[s[i]] + 1;
            hash[s[i]] = i;
            result = max(result, i - left + 1);
        }
        return result;
    }
};