class Solution {
public:
    string processStr(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                st.push_back(s[i]);
            }else if(s[i]=='*' && st.size()!=0){
                st.pop_back();
            }else if(s[i]=='#'){
                string v=st;
                st=st+v;
            }else{
                reverse(st.begin(),st.end());
            }
        }
        return st;
    }
};
