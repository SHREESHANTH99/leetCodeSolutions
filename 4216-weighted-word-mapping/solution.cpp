class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(int i=0;i<words.size();i++){
            int cnt=0;
            for(char c:words[i]){
                cnt+=weights[c-'a'];
            }
            int val=cnt%26;
            s.push_back(char('z'-val));
        }
        return s;
    }
};
