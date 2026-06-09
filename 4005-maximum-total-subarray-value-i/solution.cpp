class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minn=*min_element(nums.begin(),nums.end());
        int maxx=*max_element(nums.begin(),nums.end());
        int diff=maxx-minn;
        return (double)diff*(double)k;
    }
};
