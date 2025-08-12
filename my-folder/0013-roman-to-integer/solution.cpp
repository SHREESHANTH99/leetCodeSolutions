class Solution {
public:
    int romanToInt(string s) {
          unordered_map<char, int> romanMap = {{'I', 1},{'V', 5}, {'X', 10}, {'L', 50},{'C',100},  {'D', 500}, {'M', 1000}};
        int t=0;
        for(int i=0;i<s.length();i++){
           if (i + 1 < s.length() && romanMap[s[i]] < romanMap[s[i + 1]]) {
            t += romanMap[s[i + 1]] - romanMap[s[i]];
            i++;
        }
        else{
            t+=romanMap[s[i]];
        }
        }
        return t;
    }
};
