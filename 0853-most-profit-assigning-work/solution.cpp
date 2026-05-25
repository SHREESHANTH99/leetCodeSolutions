class Solution {
public:
    int lower_bound(vector<int>& difficulty, vector<int>& profit,int x){
        int low=0;
        int high=profit.size()-1;
        int ind=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(difficulty[mid]<=x){
                ind=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ind;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int p=worker.size();
        int sum=0;
        vector<pair<int,int>> jobs;

        for(int i=0;i<difficulty.size();i++){
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(int i=0;i<difficulty.size();i++){
            difficulty[i] = jobs[i].first;
            profit[i] = jobs[i].second;
        }
        vector<int> best(profit.size());
        best[0] = profit[0];
        for(int i=1; i<profit.size(); i++){
            best[i] = max(best[i-1], profit[i]);
        }
        for(int i=0;i<p;i++){
            int p=lower_bound(difficulty,profit,worker[i]);
            if(p!=-1){
                sum+=best[p];
            }
        }
        return sum;
    }
};
