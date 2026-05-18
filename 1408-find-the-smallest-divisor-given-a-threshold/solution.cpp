class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        long long maxx=INT_MIN;
        for(long long i=0;i<n;i++){
            maxx=max(maxx,(long long)nums[i]);
        }
        int low=1;int high=maxx;
        while(low<=high){
            int mid=(low+high)/2;long long sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/(double)mid);
            }
            if(sum<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
