class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long strg=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long num1=nums[i];
                long long num2=nums[j];
                long long g=gcd(num1,num2);
                long long curr_strg=num1*num2/(g*g);
                strg=max(curr_strg,strg);
            }
        }
        return strg;
    }
};
