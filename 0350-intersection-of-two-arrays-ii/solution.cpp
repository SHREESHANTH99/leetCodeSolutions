class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums1[i]]++;
        }
        vector<int> ans;
        for(int x:nums2){
            if(freq[x]>0){
                ans.push_back(x);
                freq[x]--;
            }
        }
        return ans;
    }
};
