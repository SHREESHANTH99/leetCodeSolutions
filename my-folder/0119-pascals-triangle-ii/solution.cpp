class Solution {
public:
    vector<int> getRow(int ro) {
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(1);
        int r=ro+1;
        for(int col=1;col<r;col++){
            ans=ans*(r-col);
            ans=ans/col;ansRow.push_back(ans);
        }
        return ansRow;
    }
};
