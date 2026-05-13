class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt=floor(nums.size()/3)+1;
        map<int,int> mp;
        vector<int> ls;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==cnt){
                ls.push_back(nums[i]);
            }
        }
        return ls;
    }
};
