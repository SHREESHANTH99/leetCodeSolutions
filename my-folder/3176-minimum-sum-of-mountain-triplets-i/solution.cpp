class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int sum=INT_MAX;
        for(int i=0;i<nums.size()-2;++i){
            for(int j=i+1;j<nums.size()-1;++j){
                for(int k=j+1;k<nums.size();++k){
                    if(nums[i]<nums[j] && nums[k]<nums[j]){
                        sum=min(sum,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        if(sum==INT_MAX){
            sum=-1;
        }
        return sum;
    }
};
