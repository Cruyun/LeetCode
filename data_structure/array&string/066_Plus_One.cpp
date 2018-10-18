class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        int len = digits.size();
        for (int i = len - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        int len = digits.size();
        for (int i = len - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

