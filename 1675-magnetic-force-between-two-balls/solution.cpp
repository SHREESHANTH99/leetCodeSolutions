class Solution {
public:
    bool cnWePlace(vector<int>& position,int d,int m){
        int cntCows=1;int last=position[0];
        for(int i=0;i<position.size();i++){
            if(position[i]-last>=d){
                cntCows++;
                last=position[i];
            }
        }
        if(cntCows>=m) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;int high=position[position.size()-1]-position[0];
        while(low<=high){
            int mid=(high+low)/2;
            if(cnWePlace(position,mid,m)==true) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
