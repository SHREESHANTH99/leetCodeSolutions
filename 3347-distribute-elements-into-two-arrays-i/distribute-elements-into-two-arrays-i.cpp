class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int a=0;
        int b=0;
        for(int i=2;i<n;i++){
            if(arr1[a]>=arr2[b]){
                arr1.push_back(nums[i]);
                a++;
            }else{
                arr2.push_back(nums[i]);
                b++;
            }
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};