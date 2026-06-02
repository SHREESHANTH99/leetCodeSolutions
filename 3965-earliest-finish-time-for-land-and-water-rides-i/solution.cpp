class Solution {
public:
    int ride(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd){
        int mnn=INT_MAX;
        for(int i=0;i<lt.size();i++){
            mnn=min(mnn,lt[i]+ld[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<wd.size();i++){
            ans=min(ans,max(mnn,wt[i])+wd[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd) {
        return min(ride(lt,ld,wt,wd),ride(wt,wd,lt,ld));
    }
};
