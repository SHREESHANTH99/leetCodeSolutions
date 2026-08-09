class Solution {
public:
    vector<vector<int>> pre;
    int m,n;
    int sqrSum(int r,int c,int k){
        int r2=r+k;
        int c2=c+k;
        return pre[r2][c2]-pre[r][c2]-pre[r2][c]+pre[r][c];
    }
    bool check(int k){
        int mnr=INT_MAX;
        int mnc=INT_MAX;
        int mxc=INT_MIN;
        for(int r=0;r+k<=m;r++){
            for(int c=0;c+k<=n;c++){
                if(sqrSum(r,c,k)!=k*k) continue;
                if(mnr!=INT_MAX){
                    if(r-mnr>=k) return true;
                    if(c-mnc>=k || mxc-c>=k) return true;
                }
                mnr=min(mnr,r);
                mnc=min(mnc,c);
                mxc=max(mxc,c);
            }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        pre.assign(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        int l=1,hi=min(m,n);
        int bst=0;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(check(mid)) {
                bst=mid;
                l=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return bst*bst;
    }
};
