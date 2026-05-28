class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        for(int i=1;i<n;i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        for(int k=0;k<queries.size();k++){
            int low=0;int high=n-1;int mB=0;
            while(low<=high){
                int mid=(low+high)/2;
                if(items[mid][0]<=queries[k]){
                    mB=items[mid][1];
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            queries[k]=mB;
        }
        return queries;
    }
};
