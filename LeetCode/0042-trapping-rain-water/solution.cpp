class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=n-1;
        int total=0;
        while(l<r){
            if(h[l]<=h[r]){
                if(lmax>h[l]){
                    total+=(lmax-h[l]);
                }else{
                    lmax=h[l];
                }
                l=l+1;
            }else{
                if(rmax>h[r]){
                    total+=(rmax-h[r]);
                }else{
                    rmax=h[r];
                }
                r=r-1;
            }
        }
        return total;
    }
};
