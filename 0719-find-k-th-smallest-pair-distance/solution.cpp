class Solution {
public:
    int countP(vector<int>& nums,int mid){
        int cnt=0;
        int j=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            while(nums[i]-nums[j]>mid){
                j++;
            }
            cnt+=i-j;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int n=nums.size();
        int high=nums[n-1]-nums[0];
        while(low<high){
            int mid=low+(high-low)/2;
            int pairC=countP(nums,mid);
            if(pairC<k) low=mid+1;
            else high=mid;
        }
        return low;
    }
};
