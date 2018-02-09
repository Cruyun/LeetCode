class Solution {
public:
    string countAndSay(int n) {
        string result;
        string lastRes = "1";

        if (n == 0) {
            lastRes = "";
        } else if (n == 1) {
            lastRes = "1";
        } else {
            for (int i = 1; i < n; i++) {
                int len = lastRes.size();

                for (int j = 0; j < len; j++) {
                    int count = 1;

                    while ((lastRes[j] == lastRes[j + 1]) && (j + 1 < len)) {
                        count++;
                        j++;
                    }
                    result += to_string(count) + lastRes[j];
                }
                lastRes = result;
                result.clear();
            }
        }
        return lastRes;
    }
};