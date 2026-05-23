class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int zero=0;
        for(int x:nums){
            if(x==0){
                zero++;
            }
        }
        int limit=n-zero;
        for(int i=0;i<limit;i++){
            if(nums[i]==0){
                count++;
            }
        }
        return count;
    }
};
