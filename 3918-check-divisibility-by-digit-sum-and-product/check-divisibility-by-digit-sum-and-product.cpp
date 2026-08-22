class Solution {
public:
    int dsum(int n){
        int sum=0;
        int digt;
        while(n>0){
            digt=n%10;
            sum+=digt;
            n=n/10;
        }
        return sum;
    }
    int dmul(int n){
        int mul=1;
        int digt;
        while(n>0){
            digt=n%10;
            mul*=digt;
            n=n/10;
        }
        return mul;
    }
    bool checkDivisibility(int n) {
        int sum=dsum(n);
        int mul=dmul(n);
        if(n%(sum+mul)==0){
            return true;
        }
        return false;
    }
};