class Solution {
public:
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right,vector<int> &ans) {
    vector<pair<int,int>> sortArr(right-left+1);
    int i=left;
    int j=mid+1;
    int k=0;
    int sOR=0;
    while (i <=mid && j <=right) {
        if (nums[i].first<=nums[j].first) {
            ans[nums[i].second]+=sOR;
            sortArr[k]=nums[i];
            i++;k++;
        } else {
            sOR++;
            sortArr[k]=nums[j];
            j++;k++;
        }
    }
    while(i<=mid){
        ans[nums[i].second]+=sOR;
        sortArr[k]=nums[i];
        i++;k++;
    }
    while(j<=right){
        sortArr[k]=nums[j];
        j++;k++;
    }
    i=left;
    k=0;
    while(i<=right){
        nums[i]=sortArr[k];
        i++;k++;
    }
}
    void mergeSort(vector<pair<int, int>>& arr, int left, int right,vector<int> &ans) {
        if (left >= right) return; 
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid,ans);
        mergeSort(arr, mid + 1, right,ans);
        merge(arr, left, mid, right,ans); 
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]={nums[i],i};
        }
        vector<int> ann(nums.size(),0);
        mergeSort(ans,0,ans.size()-1,ann);
        return ann;
    }
};
