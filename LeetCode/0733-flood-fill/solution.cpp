class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>>& image,int newColor,int dr[],int dc[],int initColor){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            image[nrow][ncol]==initColor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,ans,image,newColor,dr,dc,initColor);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr,sc,ans,image,color,dr,dc,initColor);
        return ans;
    }
};
