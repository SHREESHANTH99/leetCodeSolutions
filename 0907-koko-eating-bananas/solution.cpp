class Solution {
public:
    int findMax(vector<int>& v){
        int maxx=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxx=max(maxx,v[i]);
        }
        return maxx;
    }

    long long calculateTotalHours(vector<int>& v,int h){
        long long tH=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            tH += ceil((double)v[i]/(double)h);
        }

        return tH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=findMax(piles);

        while(low<=high){

            int mid=(low+high)/2;

            long long tH=calculateTotalHours(piles,mid);

            if(tH<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
};
