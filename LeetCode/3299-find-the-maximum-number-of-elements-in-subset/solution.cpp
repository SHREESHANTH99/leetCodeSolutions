class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int res=mp[1]-1 | 1;
        mp.erase(1);
        for(auto& f:mp){
            int n=0;
            int x=f.first;
            int sq=sqrt(x);
            if(sq*sq==x && mp.count(sq) && mp[sq]>1){
                continue;
            }
            while(x<31623 && mp.count(x) && mp[x]>1){
                n+=2;
                x*=x;
            }
            res=fmax(res,n+((mp.count(x)<<1)-1));
        }
        return res;
    }
};
