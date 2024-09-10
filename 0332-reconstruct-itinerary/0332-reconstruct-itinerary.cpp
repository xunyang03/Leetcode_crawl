class Solution {
private:
    // map为有序结构从而达成排序的目的
    unordered_map<string, map<string, int>> record; // [起点, (终点, 此航线次数)]
    int num_tickets = 0;    
public:
    bool arrangeFlight(vector<string>& result){
        if (result.size() == num_tickets + 1) 
            return true;
        // 若不存在以当前末尾为起点的下一班行程，则当前排序不满足，需回溯
        if (record.find(result[result.size() - 1]) == record.end())
            return false;
        for (auto& dest : record[result[result.size() - 1]]){
            if (dest.second > 0){ // 防止进入死循环
                result.push_back(dest.first);
                dest.second--;
                if (arrangeFlight(result)) return true;
                dest.second++;
                result.pop_back(); // 回溯
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets){
            record[ticket[0]][ticket[1]]++;
            num_tickets++;
        }
        vector<string> result;
        result.push_back("JFK");
        arrangeFlight(result);
        return result;
    }
};