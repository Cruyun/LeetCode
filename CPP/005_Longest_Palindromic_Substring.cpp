class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool table[n][n];
        memset(table, 0, sizeof(table));

        int maxLen = 1;
        int i, j, k;
        int start = 0;

        for (i = 0; i < n; i++) {
            table[i][i] = true;
        }

        for (i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        for (k = 3; k <= n; k++) {
            for (i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (table[i + 1][j - 1] == true && s[i] == s[j]) {
                    table[i][j] = true;
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        string substr = "";
        for( i = start; i <= start + maxLen - 1; ++i ) {
            substr += s[i];
        }
        return substr;
    }
};