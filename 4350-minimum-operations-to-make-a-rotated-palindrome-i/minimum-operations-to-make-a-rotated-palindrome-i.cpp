class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int k=0;k<n;k++){
            int curr_ops=0;
            for(int i=0;i<n/2;i++){
                char leftChr=s[(i+k)%n];
                char rightChr=s[(n-1-i+k)%n];
                int x=(leftChr-rightChr+26)%26;
                int y=(-leftChr+rightChr+26)%26;
                curr_ops+=min(x,y);
            }
            ans=min(ans,curr_ops+k);
        }
        return ans;
    }
};