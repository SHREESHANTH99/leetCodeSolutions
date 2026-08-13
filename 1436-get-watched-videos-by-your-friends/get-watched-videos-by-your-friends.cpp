class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        q.push(id);
        int n=friends.size();
        vector<int> dist(n,-1);
        dist[id]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:friends[node]){
                if(dist[it]==-1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
                
            }
        }
        unordered_map<string,int> mp;
        for(int i=0;i<dist.size();i++){
            if(dist[i]==level){
                for(string videos:watchedVideos[i]){
                    mp[videos]++;
                }
            }
        }
        vector<string> ans;
        for(auto &[video,count]:mp){
            ans.push_back(video);
        }
        sort(ans.begin(),ans.end(),[&](string &a,string b){
            if(mp[a]!=mp[b]){
                return mp[a] < mp[b];
            }
            return a< b;
        });
        return ans;

    }
};