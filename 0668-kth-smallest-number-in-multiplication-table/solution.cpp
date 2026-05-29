class Solution {
public:
    int noOfNoLessThan(int x,int n,int m){
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=min(n,x/i);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(noOfNoLessThan(mid,n,m)<k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
