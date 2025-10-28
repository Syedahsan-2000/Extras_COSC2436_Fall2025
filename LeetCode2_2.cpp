// isHappy function implemented using unordered_map<int,bool> lines 5-25
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> Numseen;

        while (n != 1) {
            if (Numseen[n]) { // if we’ve seen this number before → loop
                return false;
            }
            Numseen[n] = true; // mark current number as seen

            int sum = 0;
            int temp = n;
            while (temp > 0) {
                int digit = temp % 10;
                sum += digit * digit;
                temp /= 10;
            }
            n = sum;
        }

        return true;
    }
};
