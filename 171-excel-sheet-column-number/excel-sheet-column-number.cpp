class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long answer = 0, temp = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            answer += (columnTitle[i] - '@') * temp;
            temp *= 26;
        }
        return answer;
    }
};