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

    long long calculateTime(vector<int>& v,long long h){
        long long tH=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            tH += h/v[i];
        }

        return tH;
    }
    long long minimumTime(vector<int>& time, long long k) {
        long long low=1;
        long long high= 1LL * (*min_element(time.begin(), time.end())) * k;
        while(low<high){
            long long mid=(low+high)/2;
            long long tC=calculateTime(time,mid);
            if(tC>=k){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
};
