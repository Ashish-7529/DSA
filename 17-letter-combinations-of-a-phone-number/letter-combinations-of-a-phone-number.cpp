class Solution {
public:
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string s = "";
        backtrack(digits, s, mp, 0);
        return ans;
    }

    void backtrack(string& digits, string& s, unordered_map<int, string>& mp, int index) {
        if (s.size() == digits.size()) {
            ans.push_back(s);
            return;
        }
        
        string t = mp[digits[index] - '0'];
        for (int i = 0; i < t.size(); i++) {
            s.push_back(t[i]);
            backtrack(digits, s, mp, index + 1);
            s.pop_back();
        }
    }
};