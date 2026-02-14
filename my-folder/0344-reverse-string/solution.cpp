class Solution {
public:
    void f(int i,vector<char>& s,int n){
        if(i>=n/2){
            return;
        }
        swap(s[i],s[n-i-1]);
        f(i+1,s,n);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        f(0,s,n);
    }
};
