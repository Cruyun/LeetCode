class Solution {
public:
    int mySqrt(int x) {
        long l = 1;
        long r = x;
        long mid = (l + r) / 2;
        
        while (l <= r) {
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }
        if (mid * mid > x) {
            return mid - 1;
        }
        return mid;
    }
};