class Solution {
public:
    bool exists(vector<vector<int>>& prefix,int mid,int threshold,int n,int m){
        for(int i=mid;i<=n;i++){
            for(int j=mid;j<=m;j++){
                int sum = prefix[i][j] - prefix[i-mid][j]
                        - prefix[i][j-mid] + prefix[i-mid][j-mid];
                if (sum <= threshold) return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        int maxLength=0;
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j] =mat[i - 1][j - 1]+prefix[i - 1][j]+prefix[i][j - 1]
                -prefix[i - 1][j - 1];
            }
        }
        int low=0;int high=min(n,m);
        while(low<=high){
            int mid=(low+high)/2;
            if(exists(prefix,mid,threshold,n,m)){
                maxLength=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return maxLength;
    }
};
