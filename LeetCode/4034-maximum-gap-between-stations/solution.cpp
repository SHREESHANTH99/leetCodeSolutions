class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        vector<int> dist(n);
        int m=station.size();
        if(n<=1){
            return 0;
        }
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m && station[j]!=skill[i]){
                j++;
            }
            dist[i]=j;
            j++;
        }
        vector<int> R(n);
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && station[j]!=skill[i]){
                j--;
            }
            R[i]=j;
            j--;
        }
        int mxGap=0;
        for(int i=1;i<n;i++){
            mxGap=max(mxGap,R[i]-dist[i-1]);
        }
        return mxGap;
    }
};
