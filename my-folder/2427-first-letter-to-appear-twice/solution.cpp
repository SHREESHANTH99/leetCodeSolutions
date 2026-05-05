class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> result;
        for(int i=0;i<s.length();++i){
            for(int j=i+1;j<s.length();++j){
                if(s[i]==s[j]){
                    int a=j;
                    result.push_back(a);
                }
            }
        }
        sort(result.begin(), result.end());
        return s[result[0]];
    }
};
