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

    long long calculateOperations(vector<int>& v,int h){
        long long tH=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            tH += ceil(((double)v[i]-(double)h)/(double)h);
        }

        return tH;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int low=1;
        int high=findMax(nums);
        while(low<=high){
            long long mid=(low+high)/2;
            long long tO=calculateOperations(nums,mid);
            if(tO<=maxOperations){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
