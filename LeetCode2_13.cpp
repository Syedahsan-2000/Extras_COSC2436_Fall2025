#include <vector>
#include <queue>
using namespace std;
// last stone weight priority queue
// **imp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
            
        }

        if (maxHeap.empty()) {
           return 0;
        }
        else {
          return maxHeap.top();
        }


    }
};
