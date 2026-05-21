class Solution {
public:
    int maxElement(vector<vector<int>>& mat,int n,int m,int x){
        int maxx=INT_MIN;
        int index=0;
        for (int i = 0; i < n; i++) {
            if (mat[i][x] > maxx) {
                maxx = mat[i][x];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int n=mat.size();
        int m=mat[0].size();
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=maxElement(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1]:-1;
            int right=mid+1<m ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};
