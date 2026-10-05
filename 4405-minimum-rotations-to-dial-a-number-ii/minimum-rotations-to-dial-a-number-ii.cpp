class Solution {
public:
    int dist(char a,char b){
        int x=abs((a-'0')-(b-'0'));
        return min(x,10-x);
    }
    int minRotations(int n, string s) {
        int pref=0;
        int suf=0;
        for(int i=n-2;i>=0;i--){
            suf+=dist(s[i],s[i+1]);
        }
        int mn=INT_MAX;
        pref=dist('0',s[0]);
        for(int k=0;k<n;k++){
            int curr=0;
            if(k==0){
                curr=dist('0',s[n-1])+suf;            
            }
            else{
                suf-=dist(s[k-1],s[k]);
                curr=pref+dist(s[k-1],s[n-1])+suf;
                pref+=dist(s[k-1],s[k]);
            }
            mn=min(mn,curr);
        }
        return mn;
    }
};