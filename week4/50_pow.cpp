class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        
        // // overflow
        if (n == INT_MIN) {
            return myPow(1/x, -(n/2)) * myPow(1/x, -(n/2));
        }
        
        if (n < 0) {
            return myPow(1/x, -n);
        }
        
        
        if (n % 2 == 0) {
            double half = myPow(x, n/2);
            return half * half;
        } else {
            double half = myPow(x, n/2);
            return half * half * x;
        }
    }
};
