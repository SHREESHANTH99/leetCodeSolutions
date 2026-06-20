class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> illu(n+1,0);
        for(int i=0;i<n;i++){
            int v=lights[i];
            if(v>0){
                int L=max(0, i-v);
                int R=min(n - 1, i + v);
                illu[L]++;
                illu[R+1]--;
            }
        }
        vector<int> fill(n);
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=illu[i];
            fill[i]=(curr>0);
        }
        int ans=0;
        for(int i=0;i<n;){
            if(fill[i]){
                i++;
                continue;
            }
            int j=i;
            while(j<n && !fill[j]) j++;
            int len=j-i;
            ans+=(len+2)/3;
            i=j;
        }
        return ans;
    }
};
