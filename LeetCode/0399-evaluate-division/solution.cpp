class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adj;
    unordered_map<string,bool> visited;
    double ans;
    bool dfs(string strt,string end,double runPrdct){
        if(adj.find(strt)==adj.end() || adj.find(end)==adj.end()){
            return false;
        }
        if(strt==end && adj.find(strt)!=adj.end()){
            ans=runPrdct;
            return true;
        }
        bool temp=false;
        visited[strt]=true;
        for(int i=0;i<adj[strt].size();i++){
            if(!visited[adj[strt][i].first]){
                temp=dfs(adj[strt][i].first,end,runPrdct*adj[strt][i].second);
                if(temp){
                    break;
                }
            }
        }
        visited[strt]=false;
        return temp;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        int m=queries.size();
        vector<double> anss(m);
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;

        }
        for(int i=0;i<m;i++){
            ans=1;
            bool pthFound=dfs(queries[i][0],queries[i][1],1);
            if(pthFound) anss[i]=ans;
            else anss[i]=-1;
        }
        return anss;
    }
};
