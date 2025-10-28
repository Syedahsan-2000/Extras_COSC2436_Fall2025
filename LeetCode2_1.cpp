// bool isAnagram function solved using unordered_map<char,int> lines 8-29
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int>freq;
        for(char c: s){

            freq[c]++;

        }
        for(char c: t)
        {
            freq[c]--;
            if(freq[c]<0)
            {
                return false;
            }
        }
        return true;
        
    }
};