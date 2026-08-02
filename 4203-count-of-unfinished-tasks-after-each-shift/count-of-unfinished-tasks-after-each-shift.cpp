class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + tasks[i];
        }
        vector<int> ans;
        ans.reserve(shifts.size());
        long long curr=0;
        for(int i=0;i<shifts.size();i++){
            curr+=shifts[i];
            if(curr>=prefSum[n]){
                curr=0;
                ans.push_back(0);
            }else{
                int res=upper_bound(prefSum.begin(),prefSum.end(),curr)-prefSum.begin();
                ans.push_back(n-res+1);
            }
        }
        return ans;
    }
};