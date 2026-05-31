class Solution {
public:
    int slidingWindow(string s,int k,char target){
        int n=s.length();
        int right=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char currEl=s[i];
            while(currEl!=target && k==0){
                if(s[right]!=target){
                    k++;
                }
                right++;
            }
            if(currEl!=target){
                k--;
            }
            ans=max(ans,i-right+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(slidingWindow(s,k,'T'),slidingWindow(s,k,'F'));
    }
};
