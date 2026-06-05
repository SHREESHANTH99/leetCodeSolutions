class Solution {
public:
    vector<string> res;
    string p;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void backTrc(string &digits,int idx){
        if(idx==digits.size()){
            res.push_back(p);
            return;
        }
        int digit=digits[idx]-'0';
        string letters=mp[digit];
        for(char c:letters){
            p.push_back(c);
            backTrc(digits,idx+1);
            p.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backTrc(digits,0);
        return res;
    }
};
