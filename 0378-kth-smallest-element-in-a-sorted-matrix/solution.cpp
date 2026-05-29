class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
