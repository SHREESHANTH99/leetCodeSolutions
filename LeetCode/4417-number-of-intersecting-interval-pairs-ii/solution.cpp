class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> start(n);
        for(int i=0;i<n;i++){
            start[i]=intervals[i][0];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int k=upper_bound(start.begin()+i+1,start.end(),intervals[i][1])-start.begin();
            ans+=k-i-1;
        }
        return ans;
    }
};
