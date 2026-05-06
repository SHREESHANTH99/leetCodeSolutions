class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int Maxprofit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>minPrice){
                Maxprofit=max(Maxprofit,prices[i]-minPrice);
            }else{
                minPrice=prices[i];
            }
        }
        return Maxprofit;
    }
};
