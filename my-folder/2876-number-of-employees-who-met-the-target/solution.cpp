class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& nums, int target) {
        int targetHours=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                targetHours+=1;
            }
        }
        return targetHours;
    }
};
