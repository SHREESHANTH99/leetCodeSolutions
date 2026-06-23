class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n && !s.empty()){
                ans[i]=s.empty() ? -1:s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};
