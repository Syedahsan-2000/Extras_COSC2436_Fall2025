// maxSlidingWindow question using priority_queue
// **imp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& 
    nums, int k) {
        priority_queue<pair<int, int>> maxHeap; 
        //  {value, index}
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Push current element with its index
            maxHeap.push({nums[i], i});

            // Remove elements that are 
            //out of the current window
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            // Start adding results once we reach window size k
            if (i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }

        return result;
    }
};
