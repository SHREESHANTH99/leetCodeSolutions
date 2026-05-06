class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<nums.size()-1;++i){
            if(i<nums.size()){
                if(nums[i]==nums[i+1]){
                ans=nums[i];
                }
            }
        }
        return ans;
    }
};
