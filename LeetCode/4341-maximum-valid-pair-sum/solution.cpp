class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long best=nums[0];
        for(int i=k;i<n;i++){
            best=max(best,1LL*nums[i-k]);
            ans=max(ans,best+nums[i]);
        }
        return ans;
    }
};
