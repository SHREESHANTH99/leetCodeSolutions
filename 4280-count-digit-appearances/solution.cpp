class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for(char c:s){
                if(c-'0'==digit){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
