class Solution {
public:
    // x^n = x^{n/2} * x^{n/2}* x^{n%2}
    //  n = Intege.MIN_VALUE，n = -n 会出现溢出，可以先将 n / 2 赋值给 t，再将 t = -n
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        int t = n / 2;
        if (n < 0) {
            t = -t;
            x = 1 / x;
        }
        double v = myPow(x, t);
        if (n % 2 == 0) return v * v;
        return x * v * v;
        
    }
    
};