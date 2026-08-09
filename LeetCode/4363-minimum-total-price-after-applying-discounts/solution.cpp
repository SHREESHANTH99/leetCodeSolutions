class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int i=0;
        int j=0;
        double sum=0.0;
        while(j< prices.size()){
            if(i<discounts.size()){
                sum+=(prices[j]*(100.0-discounts[i])/100.0);
                i++;j++;
            }else{
                sum+=(prices[j]);
                j++;
            }
        }
        return sum;
    }
};
