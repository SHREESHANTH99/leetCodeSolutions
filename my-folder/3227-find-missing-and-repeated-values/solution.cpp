class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> hash(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[nums[i][j]]++;
            } 
        }
        int missing =-1;
        int repeated =-1;
        for(int i=1;i<=n*n;i++){
            if(hash[i]==0){
                missing =i;
            }
            if(hash[i]==2){
                repeated=i;
            }
        }
        return {repeated,missing};
    }
};
