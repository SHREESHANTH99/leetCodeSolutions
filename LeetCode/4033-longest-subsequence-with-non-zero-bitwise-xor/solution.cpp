class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int left=0;
        int xorr=0;
        int n=nums.size();
        bool allZ=true;
        for(int right=0;right<nums.size();right++){
            xorr^=nums[right];
            if(nums[right]!=0){
                allZ=false;
            }
        }
        if(allZ){
            return 0;
        }
        if(xorr!=0){
            return n;
        }
        return n-1;
    }
};
