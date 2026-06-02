class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int id = num - 1;
            if(nums[id]<0){
                ans.push_back(num);
            }else{
                nums[id]*=-1;
            }
        }
        return ans;
    }
};
