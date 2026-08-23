class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();int m=upper-lower+1;
        vector<bool> isPres(m,false);
        for(int num:nums){
            if(num>=lower && num<=upper){
                isPres[num-lower]=true;
            }
        }
        vector<vector<int>> res;
        int st=-1;
        for(int i=0;i<m;i++){
            int currNum=lower+i;
            if(!isPres[i]){
                if(st==-1){
                    st=currNum;
                }
            }else{
                if(st!=-1){
                    res.push_back({st,currNum-1});
                    st=-1;
                }
            }
        }
        if(st!=-1){
            res.push_back({st,upper});
        }
        return res;
    }
};
