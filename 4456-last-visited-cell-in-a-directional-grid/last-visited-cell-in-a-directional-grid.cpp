class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int i=0,j=0;
        int lsti=0,lstj=0;
        while(i>=0 && i<m && j>=0 && j<n && vis[i][j]!=1){
            vis[i][j]=1;
            lsti=i;
            lstj=j;
            if(grid[i][j]=='R'){
                j++;
            }else if(grid[i][j]=='L'){
                j--;
            }else if(grid[i][j]=='D'){
                i++;
            }else{
                i--;
            }
        }
        return {lsti,lstj};
    }
};