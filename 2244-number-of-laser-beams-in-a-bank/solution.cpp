class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int as=0;
        int cnt=0;
        for(int i=0;i<bank.size();i++){
            int sum=0;
            for(char c:bank[i]){
                if(c=='1'){
                    sum++;
                }
            }
            if(sum == 0) continue;
            cnt += (as * sum);
            as = sum;
        }
        return cnt;
    }
};
