class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0, bill_10 = 0;
        for (int i = 0; i < bills.size(); i++){
            if (bills[i] == 5) bill_5++;
            if (bills[i] == 10){
                if (bill_5 <= 0) return false;
                bill_5--;
                bill_10++;
            }
            if (bills[i] == 20){
                if (bill_5 <= 0) return false;
                if (bill_10 > 0){
                    bill_10--;
                    bill_5--;
                }
                else{
                    if (bill_5 < 3) return false;
                    bill_5 -= 3;
                }
            }
        }
        return true;
    }
};