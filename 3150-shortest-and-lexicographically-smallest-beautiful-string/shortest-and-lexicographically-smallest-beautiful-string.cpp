class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int n=s.size();
        string ans="";
        int ones_count=0;
        for(int right=0;right<n;right++){
            if(s[right]=='1') ones_count++;
            while(ones_count==k){
                string b=s.substr(left,right-left+1);
                int len=right-left+1;
                if(ans == "" || len < ans.size() || (len == ans.size() && b < ans)){
                    ans=b;
                }
                if(s[left]=='1'){
                ones_count--;

            }                
            left++;
            }
            
        }
        return ans;
    }
};