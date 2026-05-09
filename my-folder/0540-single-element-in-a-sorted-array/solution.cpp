class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int length=nums[n-1]+1;
        vector<int> hash(length);
        for(int i=0;i<n;++i){
            hash[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(hash[nums[i]]==1){
                ans=nums[i];
            }
        }
        return ans;
    }
};
