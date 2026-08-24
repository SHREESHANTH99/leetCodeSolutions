class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n);
        queue<int> q;
        for(int num:rooms[0]){
            q.push(num);
            vis[num]=true;
        }
        vis[0]=true;
        while(!q.empty()){
            int rm=q.front();
            q.pop();
            for(int room:rooms[rm]){
                if(!vis[room]){
                    vis[room]=true;
                    q.push(room);
                }
            }
        }
        for(bool x:vis){
            if(x==false) return false;
        }
        return true;
    }
};