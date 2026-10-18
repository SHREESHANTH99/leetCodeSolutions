class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n=nums.size();
        int xo=nums[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(xo==nums[i]){
                ans++;
            }
            xo=nums[i];
        }
        return ans;
    }
};