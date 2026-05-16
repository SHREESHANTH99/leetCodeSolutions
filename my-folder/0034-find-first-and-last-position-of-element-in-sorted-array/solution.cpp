class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        vector<int> ans={-1,-1};
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                int l = mid;
                int r = mid;
                while(l >= 0 && nums[l] == target) {
                    l--;
                }
                while(r < n && nums[r] == target) {
                    r++;
                }
                ans[0] = l + 1;
                ans[1] = r - 1;
                return ans;
            }
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};
