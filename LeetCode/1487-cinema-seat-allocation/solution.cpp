class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto& r:reservedSeats){
            int rw=r[0];
            int seat=r[1];
            if(seat>=2 && seat <=5){
                mp[rw].insert(0);
            }
            if(seat>=4 && seat<=7){
                mp[rw].insert(1);
            }
            if(seat>=6 && seat<=9){
                mp[rw].insert(2);
            }
        }
        int tl=2*n;
        for(auto & [rw,grps]:mp){
            if(grps.size()==3){
                tl-=2;
            }else{
                tl-=1;
            }
        }
        return tl;
        
    }
};
