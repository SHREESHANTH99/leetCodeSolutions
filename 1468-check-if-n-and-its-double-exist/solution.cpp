class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(arr[j]==arr[i]*2 || arr[j]==0.5*arr[i]){
                    return true;
                    break;
                }else{
                    j++;
                }
            }
        }
        return false;
    }
};
