class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());   
        vector<int> output={};
        for(int i=0;i<nums.size();i+=2){
            output.push_back(nums[i+1]);
            output.push_back(nums[i]);
        }
        return output;
    }
};
