class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int lft=0;
        int n=nums.size();
        deque<int> mxdq;
        deque<int> mndq;
        int mxLength=0;
        for(int right=0;right<n;right++){
            while(!mxdq.empty() && nums[mxdq.back()]<nums[right]){
                mxdq.pop_back();
            }
            mxdq.push_back(right);
            while(!mndq.empty() && nums[mndq.back()]>nums[right]){
                mndq.pop_back();
            }
            mndq.push_back(right);
            while((nums[mxdq.front()]-nums[mndq.front()])> limit){
                if(mxdq.front()==lft){
                    mxdq.pop_front();
                }if(mndq.front()==lft){
                    mndq.pop_front();
                }
                lft++;
            }
            mxLength=max(mxLength,right-lft+1);
        }
        return mxLength;
    }
};