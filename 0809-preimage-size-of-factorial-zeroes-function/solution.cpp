class Solution {
public:
    long trailingZeroes(int n) {
        long ans=0;
        while(n>0){
            n=n/5;
            ans+=n;
        }
        return ans;
    }
    int preimageSizeFZF(long long k) {
        long long low=0;
        long long high=1e9;
        if(k==low || k==high) return 5;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long trail=trailingZeroes(mid);
            if(trail==k) return 5;
            else if(trail<k) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
};
