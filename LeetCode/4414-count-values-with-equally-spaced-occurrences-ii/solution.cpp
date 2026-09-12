class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(const auto&[val,ind]:mp){
            if(ind.size()>=3){
                int diff=ind[1]-ind[0];
                bool aE=true;
                for(int i=2;i<ind.size();i++){
                    if(ind[i]-ind[i-1]!=diff){
                        aE=false;
                        break;
                    }
                }
                if(aE){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
