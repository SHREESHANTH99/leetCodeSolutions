class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int r=0;r<n;r++){
            int i=r;int j=0;
            vector<int> temp;
            while(i<n && j<m){
                temp.push_back(mat[i++][j++]);
            }
            sort(temp.begin(),temp.end());
            i=r;j=0;
            int k=0;
            while(i<n && j<m){
                mat[i++][j++]=temp[k++];
            }
        }
        for (int col = 1; col < m; col++) {
            int i = 0, j = col;
            vector<int> temp;

            while (i < n && j < m) {
                temp.push_back(mat[i++][j++]);
            }

            sort(temp.begin(), temp.end());

            i = 0, j = col;
            int k = 0;
            while (i < n && j < m) {
                mat[i++][j++] = temp[k++];
            }
        }

        return mat;
    }
};
