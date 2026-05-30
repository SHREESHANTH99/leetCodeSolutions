class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        double result=(log10(n)/log10(2));
        return fmod(result,1.0)==0.0;
    }
};
