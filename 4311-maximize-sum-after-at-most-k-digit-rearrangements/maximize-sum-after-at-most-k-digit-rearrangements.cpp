class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        vector<int> gain;
        for(int x:nums){
            string s=to_string(x);
            sort(s.rbegin(),s.rend());
            int rearr=stoi(s);
            sum+=x;
            gain.push_back(rearr-x);
        }
        sort(gain.rbegin(),gain.rend());
        for(int i=0;i<k && i<gain.size();i++){
            if(gain[i]>0){
                sum+=gain[i];
            }
        }
        return sum;
    }
};