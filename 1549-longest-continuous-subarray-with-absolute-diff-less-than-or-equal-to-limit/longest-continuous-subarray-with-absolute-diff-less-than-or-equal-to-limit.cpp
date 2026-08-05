class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int lft=0;
        int n=nums.size();
        multiset<int> ms;
        int mxLength=0;
        for(int right=0;right<n;right++){
            ms.insert(nums[right]);
            while((-1)*(*ms.begin()-*ms.rbegin() )> limit){
                ms.erase(ms.find(nums[lft]));
                lft++;
            }
            mxLength=max(mxLength,right-lft+1);
        }
        return mxLength;
    }
};