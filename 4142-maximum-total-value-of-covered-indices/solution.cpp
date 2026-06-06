class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        long long ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                i++;
                continue;
            }
            int l=i;
            while(i<n && s[i]=='1') i++;
            int r=i-1;
            vector<int> v;
            if(l>0) v.push_back(nums[l-1]);
            for(int j=l;j<=r;j++){
                v.push_back(nums[j]);
            }
            int len=r-l+1;
            sort(v.begin(),v.end(),greater<int>());
            for(int k=0;k<len;k++){
                ans+=v[k];
            }
        }
        return ans;
    }
};
