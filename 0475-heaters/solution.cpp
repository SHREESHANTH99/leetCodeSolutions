class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int minRad=0;
        for(int i=0;i<houses.size();i++){
            auto it=lower_bound(heaters.begin(),heaters.end(),houses[i]);
            int cD=INT_MAX;
            if(it!=heaters.end()){
                cD=min(cD,*it-houses[i]);
            }
            if(it!=heaters.begin()){
                cD=min(cD,houses[i]-*(it-1));
            }
            minRad=max(minRad,cD);
        }
        return minRad;
    }
};
