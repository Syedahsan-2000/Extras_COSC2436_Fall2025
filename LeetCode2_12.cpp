// group Anagram using unordered_map.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // canonical form
            anagramGroups[sortedStr].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
