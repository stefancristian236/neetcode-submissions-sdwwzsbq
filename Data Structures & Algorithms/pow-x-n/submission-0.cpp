class Solution {
public:
    double myPow(double x, int n) {
        double result = x;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n > 0) {
            for (size_t p = 2; p <= n; ++p){
                result *= x;
            }
            return result;
        } else {
            int pos_n = -n;
            for (size_t p = 2; p <= pos_n; ++p){
                result *= x;
            }
            return 1 / result;
        }
        return 0;
    }
};
