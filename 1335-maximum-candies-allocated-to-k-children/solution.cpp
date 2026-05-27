class Solution {
public:    
    long long findMax(vector<int>& v){
        int maxx=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxx=max(maxx,v[i]);
        }
        return maxx;
    }

    long long calculateCandies(vector<int>& v,int h){
        long long tH=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            tH += (double)v[i]/(double)h;
        }

        return tH;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=findMax(candies);
        int result=0;
        while(low<=high){
            long long mid=(low+high)/2;
            long long tC=calculateCandies(candies,mid);
            if(tC>=k){
                result=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return result;
    }
};
