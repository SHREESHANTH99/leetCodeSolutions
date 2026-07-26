class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord)==wordSet.end()){
            return 0;
        }
        queue<string> wQ;
        wQ.push(beginWord);
        int dist=1;
        while(!wQ.empty()){
            int lSize=wQ.size();
            for(int i=0;i<lSize;i++){
                string currWord=wQ.front();
                wQ.pop();
                if(currWord==endWord){
                    return dist;
                }
                for(int j=0;j<currWord.length();j++){
                    char orgChar=currWord[j];
                    for(char c='a';c<='z';c++){
                        if(c==orgChar) continue;
                        currWord[j]=c;
                        if(wordSet.find(currWord)!=wordSet.end()){
                            wQ.push(currWord);
                            wordSet.erase(currWord);
                        }
                    }
                    currWord[j]=orgChar;
                }
            }
            dist++;
        }
        return 0;
    }
};
