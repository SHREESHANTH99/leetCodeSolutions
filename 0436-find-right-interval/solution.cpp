class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> st(n);
        for(int i=0;i<n;i++) st[i]={intervals[i][0],i};
        sort(st.begin(),st.end());
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int trget=intervals[i][1];
            int low=0;
            int high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(st[mid].first>=trget) high=mid-1;
                else low=mid+1;
            }
            if(low<n) ans[i]=st[low].second;
        }
        return ans;
    }
};
