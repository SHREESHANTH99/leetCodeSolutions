class Solution {
public:
    bool check(string s,int n){
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                return true;
                break;
            }
        }
        return false;
    }
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;
        int a=0;
        for(int i=0;i<n;i++){
            string rs=s.substr(i)+s.substr(0,i);
            int score=0;
            for(int j=0;j<n-1;j++){
                if(rs[j]==rs[j+1]){
                    score++;
                }
            }

            if(score==k){
                ans++;
            }
        }
        return ans;
    }
};
