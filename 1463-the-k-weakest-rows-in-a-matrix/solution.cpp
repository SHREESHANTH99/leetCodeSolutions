class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int sum;
        set<pair<int,int>>s;
        for(int i=0;i<mat.size();i++){
            sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum+=mat[i][j];
            }
            s.insert({sum,i});
        }

        for(auto x=begin(s);k>0;k--,x++){
            ans.push_back(x->second);
        }
        return ans;
    }
};
