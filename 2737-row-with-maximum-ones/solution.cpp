class Solution {
public:
    int lower_bound(vector<int>& mat,int n,int x){
        int low=0;int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(mat[mid]>=x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            sort(mat[i].begin(),mat[i].end());
        }
        int cnt_max=-1;
        int index=-1;
        for(int i=0;i<mat.size();i++){
            int cnt_ones=mat[i].size()-lower_bound(mat[i],mat[i].size(),1);
            if(cnt_ones>cnt_max){
                index=i;
                cnt_max=cnt_ones;
            }
        }
        return {index, cnt_max};
    }
};
