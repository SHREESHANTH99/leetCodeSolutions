class Solution {
public:
    int minPartitions(string n) {
        int m=0;
        int l=n.size();
        for(int i=0;i<l;i++){
            m=max(m,n[i]-'0');
        }
        return m;
    }
};
