class Solution {
public:
    int largestInteger(int n, int s) {
        int ans=INT_MIN;
        if(s>9*n){
            return -1;
        }
        if(s==0){
            return 0;
        }
        for(int i=pow(10,n)-1;i>=0;i--){
            int b=i;
            int sum=0;
            while(b>0){
                sum+=b%10;
                b/=10;
            }
            if(sum==s){
                ans=i;
                break;
            }
        }
        return ans;
    }
};