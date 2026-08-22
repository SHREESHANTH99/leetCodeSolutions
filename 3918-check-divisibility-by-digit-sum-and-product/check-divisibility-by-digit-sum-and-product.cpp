class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int digt;
        int mul=1;
        int m=n;
        while(n>0){
            digt=n%10;
            sum+=digt;
            mul*=digt;
            n=n/10;
        }
        if(m%(sum+mul)==0){
            return true;
        }
        return false;
    }
};