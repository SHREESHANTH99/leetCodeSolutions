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
};
