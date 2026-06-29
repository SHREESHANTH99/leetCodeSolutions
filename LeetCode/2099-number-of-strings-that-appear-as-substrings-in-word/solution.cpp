class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(auto item:patterns){
            if(word.find(item)!=string::npos){
                cnt++;
            }
        }
        return cnt;
    }
};
