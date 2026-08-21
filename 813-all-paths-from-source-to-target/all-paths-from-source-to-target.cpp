class Solution {
public:
    int trgt;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>> &graph,int currNode=0){
        tmp.push_back(currNode);
        if(currNode==trgt) res.push_back(tmp);
        else{
            for(int node:graph[currNode]){
                dfs(graph,node);
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        trgt = graph.size()-1;
        dfs(graph);
        return res;
    }
};