class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp(123);
        int left=0;
        int mxLength=0;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            while(left<=right && mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            mxLength=max(mxLength,right-left+1);
        }
        return mxLength;
    }
};
