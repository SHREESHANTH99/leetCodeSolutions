class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx_green=0;
        for(int i=0;i<lights.size();i++){
            if(lights[i]>mx_green){
                mx_green=lights[i];
            }
        }
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r= arrivalTime[i]%period;
            if(r>=mx_green){
                int curr_time=period-r;
                ans=max(ans,curr_time);
            }
            
        }
        return ans;
    }
};
