class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp(50);
        for(int i=0;i<=n-k;i++){
            unordered_set<int> st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(int x:st){
                mp[x]++;
            }
        }
        int mx=-1;
        for(const auto& [key , value]: mp){
            if(value==1){
                mx=max(mx,key);
            }
        }
        return mx;
    }
};
