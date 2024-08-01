class Solution {
public:
    typedef pair<int, int> T;
    class compare {
    public:
        bool operator()(const T& left, const T& right) {
            return left.second > right.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num : nums)
            map[num]++;
        priority_queue<T, vector<T>, compare> min_heap;
        for (auto i = map.begin(); i != map.end(); i++) {
            min_heap.push(*i);
            if (min_heap.size() > k)
                min_heap.pop();
        }

        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return result;
    }
};