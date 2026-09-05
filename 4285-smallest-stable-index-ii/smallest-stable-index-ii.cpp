class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefMax(n);
        vector<int> suffMx(n);
        prefMax[0]=nums[0];
        suffMx[n-1]=nums[n-1];
        int prf=nums[0];
        for(int i=n-2;i>=0;i--){
            suffMx[i]=min(nums[i],suffMx[i+1]);
        }
        for(int i=0;i<n;i++){
            prf=max(nums[i],prf);
            if((prf-suffMx[i])<=k){
                return i;
            }
        }
        return -1;
    }
};