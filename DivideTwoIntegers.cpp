class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = int();
        int remainder = int();
        if(!divisor || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX; 
        }
        bool pos = ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0));
        long long absDividend = labs(dividend), absDivisor = labs(divisor);
        while(absDividend >= absDivisor){
            long long temp = absDivisor, multiple = 1;
            while(absDividend >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1; 
            } 
            absDividend -= temp;
            quotient += multiple;
        }
        return (pos) ? quotient : -quotient;
    }
};
