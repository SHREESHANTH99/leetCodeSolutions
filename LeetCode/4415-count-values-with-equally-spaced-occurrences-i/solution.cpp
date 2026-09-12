class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        unordered_set<int> uniq(nums.begin(),nums.end());
        for(int x:uniq){
            int m=0;
            vector<int> ind;
            for(int j=0;j<n;j++){
                if(nums[j]==x){
                    m++;
                    ind.push_back(j);
                }
            }
            if(m==3){
                if(ind[1]-ind[0]==ind[2]-ind[1]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
