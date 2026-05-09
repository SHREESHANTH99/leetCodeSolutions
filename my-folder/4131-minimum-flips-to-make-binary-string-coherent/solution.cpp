class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int ones=count(s.begin(),s.end(),'1');
        int zeroes=n-ones;
        int t1=ones;
        int t4=zeroes;
        int t2=(ones>=1) ? ones-1:1;
        int t3=INT_MAX;
        if(n>=2){
            int intOnes=ones-(s[0]=='1' ?1:0)-(s[n-1]=='1' ?1:0);
            t3=(s[0]=='0'?1:0)+intOnes+(s[n-1]=='0' ?1:0);
        }
        return min({t1,t2,t3,t4});
    }
};
