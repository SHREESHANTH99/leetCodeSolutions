class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxx=0;
        int words=1;
        for(int i=0;i<sentences.size();i++){
            for(char c:sentences[i]){
                if(c==' '){
                    words++;
                }
            }
            maxx=max(maxx,words);
            words=1;
        }
        return maxx;
    }
};
