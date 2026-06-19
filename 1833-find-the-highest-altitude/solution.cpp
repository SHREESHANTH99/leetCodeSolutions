class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx=INT_MIN;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            maxx=max(maxx,sum);
        }
        if(maxx<0){
            return 0;
        }
        return maxx;
    }
};
