class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(char c:s){
            if(c=='*'){
                len=max(0LL,len-1);
            }else if(c=='#'){
                len *=2;
            }else if(c!='%'){
                len++;
            }
        }
        if(k>=len) return '.';
        for(int i=(int)s.size()-1;i>=0;i--){
            char c=s[i];
            if(c=='*'){
                len++;
            }
            else if(c=='#'){
                long long hlf=len/2;
                if(k>=hlf){
                    k-=hlf;
                }
                len=hlf;
            }
            else if(c=='%'){
                k=len-1-k;
            }
            else{
                if(k==len-1){
                    return c;
                }
                len--;
            }
        }
        return '.';
    }
};
