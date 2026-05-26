class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> ans;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if((arr[i]/arr[j])<1){
                    double val=(double)arr[i]/arr[j];
                    ans.push_back({val,{arr[i],arr[j]}});
                }
            }
        }
        sort(ans.begin(),ans.end());
        return {ans[k-1].second.first,ans[k-1].second.second};
    }
};
