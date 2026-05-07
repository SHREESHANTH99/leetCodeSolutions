class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(colors[i]!=colors[j]){
                    maxx=max(maxx,j-i);
                }
            }
        }
        return maxx;
    }
};
