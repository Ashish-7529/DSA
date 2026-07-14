class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;

        for(int i = n - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }

        if(carry) {
            vector<int> ans(1, 1);
            ans.insert(ans.end(), digits.begin(), digits.end());
            return ans;
        }

        return digits;
    }
};