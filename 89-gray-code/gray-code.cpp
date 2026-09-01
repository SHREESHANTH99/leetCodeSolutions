class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<(pow(2,n));i++){
            int a=i;
            a=a^(a>>1);
            ans.push_back(a);
        }
        return ans;
    }
};