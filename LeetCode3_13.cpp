// LadderLength Problem
class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordBank) {
        unordered_set<string> wordSet(wordBank.begin(), wordBank.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string,int>> bfsQueue;
        bfsQueue.push({startWord, 1});

        while(!bfsQueue.empty()) {
            auto [current, level] = bfsQueue.front();
            bfsQueue.pop();

            if(current == endWord) return level;

            for(int pos = 0; pos < current.size(); pos++) {
                char originalChar = current[pos];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch == originalChar) continue;
                    current[pos] = ch;
                    if(wordSet.count(current)) {
                        bfsQueue.push({current, level + 1});
                        wordSet.erase(current);  
                    }
                }
                current[pos] = originalChar;
            }
        }

        return 0;
    }
};
