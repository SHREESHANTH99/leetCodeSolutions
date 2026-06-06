class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> lsum(n);
        vector<int> rsum(n);
        int sum=accumulate(nums.begin(),nums.end(),0);            
        int sm=0;
        for(int i=0;i<n;i++){
            lsum[i]=sm;
            sm+=nums[i];
        }            
        int sn=0;
        for(int i=n-1;i>=0;i--){
            rsum[i]=sn;
            sn+=nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(abs(lsum[i]-rsum[i]));
        }
        return ans;
    }
};
