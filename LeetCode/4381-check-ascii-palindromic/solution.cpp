class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            int j=n-1-i;
            if(i>j) break;
            unsigned char a=s[i];
            unsigned char b=s[j];
            for(int k=0;k<8;k++){
                int bA=(a>>(7-k)) & 1;
                int bB=(b>>(k)) & 1;
                if(bA!=bB) return false;
            }
        }
        return true;
    }
};
