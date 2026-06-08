class Solution {
public:
    int reverse(int x) {
        bool ans=false;
        if(x<0){
            ans=true;
        }
        string s=to_string(x);
        string v;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                v.push_back(s[i]);
            }
        }
        long long  an=stoll(v);
        if((an>2147483648) || (an<-2147483648 )) {
            return 0;
        }
        if(ans==true){
            an=an*(-1);
        }
        return an;
    }
};
