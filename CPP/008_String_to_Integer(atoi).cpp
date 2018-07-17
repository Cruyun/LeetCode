class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while (str[index] == ' ') {
            index++;
        }
        int flag = 0;
        if (str[index] == '-') flag = 1;
        if (str[index] == '-' || str[index] == '+') {
            index++;
        }
        long long int result = 0;
        while(str[index] <= '9' && str[index] >= '0') {
            result = (str[index] - '0') + result * 10;
            index++;
            if (result > INT_MAX) {
                return (flag == 1) ? INT_MIN : INT_MAX;
            }
        }
        if (result == 0) {
            return 0;
        } else {
            return (flag == 1) ? -result : result;
        }
    }
};