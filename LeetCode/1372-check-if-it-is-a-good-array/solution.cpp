class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int bcdd=nums[0];
        for(int num:nums){
            bcdd=gcd(bcdd,num);
            if(bcdd==1){
                return true;
            }
        }
        return false;
    }
};
