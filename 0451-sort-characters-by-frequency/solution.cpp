class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        vector<pair<int,int>> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(j<s.size() && s[j]==s[i])
            j++;
            ans.push_back({j-i,s[i]});
            i=j;
        }
        sort(ans.begin(),ans.end(), [](auto &a, auto&b){
        return a.first > b.first;
        });
        string res;
        for(auto &p:ans){
            res.append(p.first,p.second);
        }
        return res;
    }
};
