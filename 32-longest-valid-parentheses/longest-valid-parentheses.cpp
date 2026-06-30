class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        // dp[i] = length of the longest valid parentheses
        // substring starting exactly at index i
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') continue;

            // Case 1: ()...
            if (i + 1 < n && s[i + 1] == ')') {
                dp[i] = 2 + dp[i + 2];
            }
            // Case 2: ( valid )
            else {
                int x = dp[i + 1];
                int idx = i + x + 1;

                if (idx < n && s[idx] == ')') {
                    dp[i] = 2 + x + dp[idx + 1];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};