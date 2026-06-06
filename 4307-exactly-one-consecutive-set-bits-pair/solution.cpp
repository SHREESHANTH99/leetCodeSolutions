class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s="";
        while(n>0){
            s+=(n%2)+'0';
            n/=2;
        }
        int cnt=0;
        for(int i=0;i+1<s.size();i++){
            if(s[i]=='1' && s[i+1]=='1'){
                cnt++;
            }
        }
        return cnt==1;
    }
};
