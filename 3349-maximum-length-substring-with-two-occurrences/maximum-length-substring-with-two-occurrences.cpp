class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left=0;
        unordered_map<char,int> mp(26);
        int mxlength=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                    mp[s[left]]--;
                    left++;
            }
            mxlength=max(mxlength,right-left+1);
        }
        return mxlength;
    }
};