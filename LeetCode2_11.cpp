// longestconsecutive using unordered_set<int>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : numSet) {  // iterate over set instead of vector
            if (numSet.find(num - 1) == numSet.end()) {  // start of sequence
                int currentNum = num;
                int currentLength = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
