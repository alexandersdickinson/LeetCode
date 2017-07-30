class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = int();
        bool pos = ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0)) ? true : false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(1){
            dividend -= divisor;
            if(dividend < 0) break;
            (pos) ? ++quotient : --quotient;
        }       
        return quotient;
    }
};
