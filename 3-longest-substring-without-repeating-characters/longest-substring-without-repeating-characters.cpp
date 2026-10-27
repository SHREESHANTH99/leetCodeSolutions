class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        unordered_map<char,int> mp;
        int lg=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            lg=max(lg,right-left+1);
        }
        return lg;
    }
};