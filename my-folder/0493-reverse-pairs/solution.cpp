class Solution {
public:
    void merge(vector<int>& vec, long long left, long long mid, long long right) {
    long long i, j, k;
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    vector<long long> leftVec(n1), rightVec(n2);
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

long long coutPairs(vector<int>& vec,long long low,long long mid,long long high){
    long long right=mid+1;long long cnt=0;
    for(long long i=low;i<=mid;i++){
        while(right<=high && vec[i]>2*(long long)vec[right]){
            right++;
        }
        cnt+=(right-(mid+1));
    }
    return cnt;
}
long long mergeSort(vector<int>& vec, long long left, long long right) {
    long long cnt=0;
    if (left < right) {
        long long mid = left + (right - left) / 2;
        cnt+=mergeSort(vec, left, mid);
        cnt+=mergeSort(vec, mid + 1, right);
        cnt+=coutPairs(vec,left,mid,right);
        merge(vec, left, mid, right);
        return cnt;
    }
    return 0;
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
