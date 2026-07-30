class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int buttons = n / 8;

        return (buttons * (buttons + 1) * 4) + (n % 8) * (buttons + 1);
    }
};