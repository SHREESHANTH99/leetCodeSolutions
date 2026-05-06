class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int exp=n*(n+1)/2;
        int act=0;
        for(int i=0;i<nums.size();++i){
            act+=nums[i];
        }
        int miss=exp-act;
        return miss;
    }
};
