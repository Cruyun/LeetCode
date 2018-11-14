/*
考察四平方和定理
任意一个正整数均可表示为4个整数（4个以内）的平方和
如果一个数除以8余7的话，那么肯定是由4个完全平方数组成
*/

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        
        for (int a = 0; a * a <= n; a++) {
            int b = sqrt(n - a * a);
            if (b * b + a * a == n) {
                return !!b + !!a;
            }
        }
        return 3;
    }
};