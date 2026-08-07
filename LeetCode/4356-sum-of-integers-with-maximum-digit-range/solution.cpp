class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans=0;
        vector<int> vec=nums;
        int max_dg_range=INT_MIN;
        for(auto& i: vec){
            int mn=INT_MAX;int mx=INT_MIN;
            while(i){
                int x=i%10;
                mn=min(mn,x);
                mx=max(mx,x);
                i=i/10;
            }
            max_dg_range=max(max_dg_range,mx-mn);
            i=mx-mn;
        }
        for(int i=0;i<nums.size();i++){
            if(vec[i]==max_dg_range){
                ans+=nums[i];
            }
        }
        return ans;
    }
};
