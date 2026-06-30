class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        int left=0;;
        vector<int> freq(3,0);
        for(int right=0;right<s.size();right++){
            freq[s[right]-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                cnt+=(n-right);
                freq[s[left]-'a']--;
                left++;
            }
        }
        return cnt;
    }
};
