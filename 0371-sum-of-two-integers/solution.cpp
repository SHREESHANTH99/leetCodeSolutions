class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry = (a & b) << 1;
            a=a^b;
            b=carry;
        }
        if (a < 0x80000000){
            return a;
        } else return ~(a ^ 0xffffffff);
    }
};
