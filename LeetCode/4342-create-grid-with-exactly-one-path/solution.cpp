class Solution {
public:
    vector<string> createGrid(int m, int n) {
        char c='.';
        char b='#';
        vector<string> grid(m,string(n,'#'));
        for(int i=0;i<m;i++) grid[i][n-1]=c;
        for(int j=0;j<n;j++) grid[0][j]=c;
        return grid;
    }
};
