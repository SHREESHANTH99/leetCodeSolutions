class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int cnt=0;
        for(auto c:tasks){
            mp[c]++;
            cnt=max(cnt,mp[c]);
        }
        int ans=(cnt-1)*(n+1);
        for(auto c:mp){
            if(c.second==cnt) ans++;
        }
        return max((int)tasks.size(),ans);
    }
};
