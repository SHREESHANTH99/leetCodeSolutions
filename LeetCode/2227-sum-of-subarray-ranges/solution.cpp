class Solution {
public:
    vector<int> nsee(vector<int> arr){
        vector<int> nse(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int> arr){
        vector<int> psee(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        return psee;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=nsee(arr);
        vector<int> psee=pse(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int lft=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*lft*1LL*arr[i]));
        }
        return total;
    }
        vector<int> nlee(vector<int> arr){
        vector<int> nle(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nle[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nle;
    }
    vector<int> ple(vector<int> arr){
        vector<int> plee(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            plee[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        return plee;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=nlee(arr);
        vector<int> psee=ple(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int lft=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*lft*1LL*arr[i]));
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMax(nums)-sumSubarrayMins(nums));
    }
};
