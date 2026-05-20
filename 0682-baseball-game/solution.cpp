class Solution {
public:
    int calPoints(vector<string>& arr) {
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            if(arr[i]=="+"){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }else if(arr[i]=="C"){
                ans.pop_back();
            }else if(arr[i]=="D"){
                ans.push_back(ans[ans.size()-1]*2);
            }else{
                ans.push_back(stoi(arr[i]));
            }
        }
        int as=0;
        for(int i=0;i<ans.size();i++){
            as+=ans[i];
        }
        return as;
    }
};
