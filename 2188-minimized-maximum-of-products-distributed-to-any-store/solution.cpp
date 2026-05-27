class Solution {
public:
    long long sum(vector<int>& v){
        long long summ=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            summ+=v[i];
        }
        return summ;
    }

    long long calculateCandies(vector<int>& v,int h){
        long long tH=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            tH += ceil((double)v[i]/(double)h);
        }

        return tH;
    }
    int minimizedMaximum(int k, vector<int>& quantities) {
        long long low=1;
        long long high=sum(quantities);
        while(low<=high){
            long long mid=(low+high)/2;
            long long tC=calculateCandies(quantities,mid);
            if(tC<=k){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};
