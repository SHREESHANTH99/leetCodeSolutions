class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0;
        int subCount=0;
        mpp[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                subCount+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return subCount;
    }
};
