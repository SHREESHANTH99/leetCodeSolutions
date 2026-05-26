class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char>st;
        for(auto s:s){
            st.insert(s);
        }
        return st.size()==26;
    }
};
