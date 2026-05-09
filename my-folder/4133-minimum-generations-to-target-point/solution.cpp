class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        using p3=tuple<int,int,int>;
        set<p3> known;
        for(auto& p:points){
            known.insert({p[0],p[1],p[2]});
        }
        p3 tgt={target[0],target[1],target[2]};
        if(known.count(tgt)) return 0;
        if(known.size()<2) return -1;
        for(int gen=1;gen<=343;gen++){
            vector<p3> snap(known.begin(),known.end());
            int sz=snap.size();
            bool added =false;
            for(int i=0;i<sz;i++){
                for(int j=i+1;j<sz;j++){
                    auto [x1,x2,x3]=snap[i];
                    auto [x21,x22,x23]=snap[j];
                    p3 np={(x1+x21)/2,(x2+x22)/2,(x3+x23)/2};
                        if(!known.count(np)){
                        known.insert(np);
                        added=true;
                        }
                }
            }
            if(known.count(tgt)) return gen;
            if (!added) break;
        }
        return -1;
    }
};
