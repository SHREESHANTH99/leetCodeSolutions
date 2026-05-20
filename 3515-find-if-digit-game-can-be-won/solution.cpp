class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int doubleD=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] >= 10 && nums[i] <= 99){
                doubleD+=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        if(sum!=doubleD) return true;
        else return false;
    }
};
