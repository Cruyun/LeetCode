class Solution {
public:
    bool isPalindrome(int x) {
        int t1 = x;
        int t2 = x;
        int mid = 0;
        
        if (x < 0) return false;
        
        while (t2 / 10) {
            mid = mid * 10 + t1 % 10;
            t1 /= 10;
            t2 /= 100;
        }
        return t2 == 0 ? t1 == mid : t1 / 10 == mid;
    }
};