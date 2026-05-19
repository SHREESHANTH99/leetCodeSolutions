class Solution {
public:
    int summ(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }
    int findDays(vector<int>& weights,int cap){
        int days=1;
        int n= weights.size();
        int load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]>cap){
                days+=1;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =*max_element(weights.begin(),weights.end());
        int high=summ(weights);
        while(low<=high){
            int mid=(low+high)/2;
            int noOfDays=findDays(weights,mid);
            if(noOfDays<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
