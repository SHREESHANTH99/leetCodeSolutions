class Solution {
public:

    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxx=0;
        int a=0;
        int b=n-1;
        while(a<b){
            maxx=max(maxx,min(height[a],height[b])*abs(b-a));           
            if(height[a]<height[b]){
                a++;
            }else{
                b--;
            }
        }
        return maxx;
    }
};
