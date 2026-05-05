class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if (nums[i]+nums[j]==target){
                    int a=i;
                    int b=j;
                    result.push_back(a);
                    result.push_back(b);
                    return result;
                }
            }
        }
        return result;
        
    }
};
