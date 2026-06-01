class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;int free=0;
        sort(cost.begin(),cost.end());
        for(int i=cost.size()-1;i>=0;i--){
            if(free==2){
                free=0;
            }else {
                ans+=cost[i];
                free+=1;
            }
        }
        return ans;
    }
};
