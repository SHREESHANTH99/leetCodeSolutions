class Solution {
public:
    bool possible(vector<int>& bloomDay, long long day, long long m, long long k){
        long long cnt=0;
        long long noofB=0;
        for(long long i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                noofB+=cnt/k;
                cnt=0;
            }
        }
        noofB+=cnt/k;
        return noofB>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        if(n<(long long)m*k) return -1;

        long long minn=INT_MAX;
        long long maxx=INT_MIN;

        for(long long i=0;i<n;i++){
            minn=min(minn,(long long)bloomDay[i]);
            maxx=max(maxx,(long long)bloomDay[i]);
        }

        long long low=minn;
        long long high=maxx;

        while(low<=high){
            long long mid=(low+high)/2;

            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return (int)low;
    }
};
