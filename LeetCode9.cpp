class Solution {
    // Length of LongestSubstring without repeating characters
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;

        
        for (int i = 0; i < n; i++) {
            string sub = ""; 
            for (int j = i; j < n; j++) {
                
                if (sub.find(s[j]) != string::npos) {
                    break;
                }
                sub += s[j];
            }
            if (sub.length() > maxLength) {
                maxLength = sub.length(); 
            }
        }

        return maxLength;
    }
};
