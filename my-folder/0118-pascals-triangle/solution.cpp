class Solution {
public:
    vector<int> generateRow(int r){
        int ans=1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1;col<r;col++){
            ans=ans*(r-col);
            ans=ans/col;ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int r) {
        vector<vector<int>> ans;
        for(int i=1;i<=r;i++){
            vector<int> temp= generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};
