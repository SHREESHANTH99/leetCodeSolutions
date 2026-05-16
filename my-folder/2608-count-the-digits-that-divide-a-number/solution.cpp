class Solution {
public:
    int countDigits(int num) {
        int val=num;
        int cnt=0;
        while(val>0){
            int n=val%10;
            if(num%n==0){
                cnt+=1;
            }
            val=val/10;
        }
        return cnt;
    }
};
