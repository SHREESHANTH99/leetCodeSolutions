class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long nd=(sum+i)/(i+1);
            ans=max(ans,nd);
        }
        return (int)ans;
    }
};
