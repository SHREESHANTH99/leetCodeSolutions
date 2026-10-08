class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;int lvl=0;
        for(char c:s){
            if(c=='('){
                if(lvl>0){
                    res+=c;
                }
                lvl++;
            }else{
                lvl--;
                if(lvl>0){
                    res+=c;
                }
            }
        }
        return res;
    }
};