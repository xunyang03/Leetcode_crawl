class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0; // gas[] - cost[] from 0
        int curSum = 0; // gas[] - cost[] from define start point
        int start = 0;
        for (int i = 0; i < gas.size(); i++){
            totalSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0){
                // clear curSum. set the new start
                curSum = 0;
                start = i + 1;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};