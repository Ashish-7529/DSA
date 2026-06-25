class Solution {
public:
    vector<string> res;

    void solve(string curr, int& n, int op, int cl) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (op < n) {
            curr.push_back('(');
            solve(curr, n, op + 1, cl);
            curr.pop_back();
        }

        if (cl < op) {
            curr.push_back(')');
            solve(curr, n, op, cl + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int op = 0;
        int cl = 0;
        solve("", n, op, cl);
        return res;
    }
};