class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mA=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1:st.top();
                mA=max(mA,heights[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int nse=(int)heights.size();
                int el=st.top();
                st.pop();
                int pse=st.empty() ? -1:st.top();
                mA=max(mA,(nse-pse-1)*heights[el]);
        }
        return mA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int mA=0;
        vector<vector<int>> mat(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        vector<vector<int>> psum(r,vector<int>(c));
        for(int j=0;j<c;j++){
            int sum=0;
            for(int i=0;i<r;i++){
                sum+=(mat[i][j]);
                if(mat[i][j]==0){
                    sum=0;
                }
                psum[i][j]=sum;
            }
        }
        for(int i=0;i<r;i++){
            mA=max(mA,largestRectangleArea(psum[i]));
        }
                    return mA;
    }
};
