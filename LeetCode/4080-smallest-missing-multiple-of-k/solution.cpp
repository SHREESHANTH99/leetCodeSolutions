class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> has(1000,0);
        for(int i=0;i<n;i++){
            has[nums[i]]++;
        }
        for(int i=1;i<1000;i++){
            if(!has[k*i]){
                return k*i;
                break;
            }
        }
        return 0;
    }
};
