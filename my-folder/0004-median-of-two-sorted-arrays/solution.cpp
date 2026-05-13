class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> arr(m+n,0);
        int i=0;int j=0;
        int k=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                arr[k]=nums1[i];
                i++;
            }else{
                arr[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<m){
            arr[k]=nums1[i];
            i++;k++;
        }
        while(j<n){
            arr[k]=nums2[j];
            j++;k++;
        }
        int a=arr.size();
        double ans=0;
        if(a%2==0){
            ans=(arr[(a/2)-1]+arr[(a/2)])/2.0;
        }else{
            ans=arr[a/2];
        }
        return ans;
    }
};
