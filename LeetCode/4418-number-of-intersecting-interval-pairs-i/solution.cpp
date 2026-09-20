class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int intersect=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(intervals[i][1]>=intervals[j][0] && intervals[j][1]>=intervals[i][0]){
                intersect++;
            }
            }
            
        }
        return intersect;
    }
};
