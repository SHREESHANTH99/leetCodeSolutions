class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        long long aT=0;
        long long l=intervals[0][0];
        long long r=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            long long l1=intervals[i][0];
            long long r1=intervals[i][1];
            if(l1<=r+1){
                r=max(r,r1);
            }else{
                aT+=(r-l+1);
                l=l1;
                r=r1;
            }
        }
        aT+=(r-l+1);
        long long bulb=(brightness+2)/3;
        return aT*bulb;
    }
};
