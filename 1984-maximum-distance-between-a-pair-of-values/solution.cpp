class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int i=0;int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums2[j]<nums1[i]){
                i++;
            }
            j++;
        }
        return max(0,j-i-1);
    }
};
