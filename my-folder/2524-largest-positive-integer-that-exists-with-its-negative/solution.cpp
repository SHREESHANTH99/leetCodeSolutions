class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxVal=-1;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[i]==-nums[j]){
                    maxVal = max(maxVal, abs(nums[i]));
                }
            }
        }
        return maxVal;
    }
};
