class Solution {
public:
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++){
            children[parent[i]].push_back(i);
        }
        vector<int> dpt(n);
        int h=0;
        stack<pair<int,int>> st;
        st.push({0,1});
        while(!st.empty()){
            auto [node,d]=st.top();
            st.pop();
            dpt[node]=d;
            h=max(h,d);
            for(int chld:children[node]){
                st.push({chld,d+1});
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(1LL*nums[i]*(h-dpt[i]+1));
        }
        return ans;
    }
};
