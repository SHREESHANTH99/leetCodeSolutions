class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            int lft=0;int rgt=i-1;
            while(lft<rgt){
                if(nums[lft]+nums[rgt]>nums[i]){
                    ans+=(rgt-lft);
                    rgt--;
                }else{
                    lft++;
                }
            }
        }
        return ans;
    }
};
