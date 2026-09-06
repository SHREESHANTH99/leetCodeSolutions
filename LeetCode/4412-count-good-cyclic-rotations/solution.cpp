class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long  t=0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        long long firstHlf=0;
        for(int i=0;i<n/2;i++){
            firstHlf+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(2*firstHlf>t){
                cnt++;
            }
            firstHlf-=nums[i];
            firstHlf+=nums[(i+n/2)%n];
        }
        return cnt;
    }
};
