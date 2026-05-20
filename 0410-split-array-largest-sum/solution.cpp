class Solution {
public:
    int countPages(vector<int>& nums, int k){
        int students=1;
        long long pagesStudent=0;
        for(int i=0;i<nums.size();i++){
            if(pagesStudent+nums[i]<=k){
                pagesStudent+=nums[i];
            }else{
                students+=1;
                pagesStudent=nums[i];
            }
        }
        return students;
    }
    int findArray(vector<int>& nums, int k){
        if(k>nums.size()) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int students=countPages(nums,mid);
            if(students>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findArray(nums,k);
    }
};
