class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>que;
        que.push({beginWord, 1});
        unordered_map<string, int> ump;
        for(auto word: wordList) ump[word]++;
        while(!que.empty()){
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();
            if(word == endWord) return steps;
            for(int i=0; i<word.size(); i++){
                char orginal = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(ump.find(word) != ump.end()){
                        ump.erase(word);
                        que.push({word, steps+1});
                    }
                }
                word[i] = orginal;
            }
        }
        return 0;
    }
};