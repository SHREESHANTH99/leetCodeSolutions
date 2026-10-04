class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int cur=0;
        int res=0;
        for(char c:s){
            int dig=c-'0';
            int d=(dig-cur+10)%10;
            res+=min(d,10-d);
            cur=dig;
        }
        return res;
    }
};