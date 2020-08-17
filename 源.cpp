#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day= (date[8] - '0') * 10 + (date[9] - '0');
        vector<int>sum_month(13);
        for (int i = 1; i <= 7; i += 2)sum_month[i] = 31;
        for (int i = 4; i <= 6; i += 2)sum_month[i] = 30;
        for (int i = 8; i <= 12; i += 2)sum_month[i] = 31;
        for (int i = 9; i <= 11; i += 2)sum_month[i] = 30;
        if (isleapyear(year))sum_month[2] = 29;
        else sum_month[2] = 28;
        int ans = 0;
        for (int i = 1; i < month; i++)ans += sum_month[i];
        return ans + day;
    }
    bool isleapyear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)return true;
        else return false;
    }
};
int main() {
    Solution sol;
    string date = "1945-04-05";
    cout << sol.dayOfYear(date);
    return 0;
}