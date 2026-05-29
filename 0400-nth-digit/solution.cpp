class Solution {
public:
    int findNthDigit(int n) {
        int dL=1;
        long long cnt=9;
        long long st=1;
        while(n>dL*cnt){
            n-=(dL*cnt);
            dL++;
            cnt*=10;
            st*=10;
        }
        long long number=st+(n-1)/dL;
        string s=to_string(number);
        return s[(n-1)%dL]-'0';
    }
};
