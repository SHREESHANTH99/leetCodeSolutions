class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans=0;
        int currFloor=0;
        for(int i=0;i<requests.size();i++){
            ans+=abs(currFloor-requests[i]);
            currFloor=requests[i];
        }
        return ans;
    }
};
