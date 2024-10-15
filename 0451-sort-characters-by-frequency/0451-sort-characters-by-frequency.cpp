class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        string res;
        while (!maxHeap.empty()) {
            auto [val, key] = maxHeap.top();
            maxHeap.pop();
            res.append(val, key);
        }

        return res; 
    }
};