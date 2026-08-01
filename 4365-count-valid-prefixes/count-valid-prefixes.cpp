class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        int z=0;
        int on=0;
        for(char c:s){
            if(c=='0') z++;
            if(c=='1') on++;
            if(abs(z-on)<=1) ans++;
        }
        return ans;
    }
};