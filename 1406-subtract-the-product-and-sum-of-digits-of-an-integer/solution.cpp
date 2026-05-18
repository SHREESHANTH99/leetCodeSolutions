class Solution {
public:
    int subtractProductAndSum(int n) {
        long long mult=1;
        long long sum=0;
        while(n>0){
            int temp=n%10;
            mult*=temp;
            sum+=temp;
            n=n/10;
        }
        return mult-sum;
    }
};
