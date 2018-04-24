class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int haystack_len = haystack.size();
        int needle_len = needle.size();

        while(i < haystack_len && j < needle_len) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i = i-j+1;
                j = 0;
            }
        }

        if(j >= needle_len)
            return i - needle_len;
        else
            return -1;
    }
};