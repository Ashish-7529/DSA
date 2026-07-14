class Solution {
public:
    string simplifyPath(string path) {
        istringstream scin(path);
        string word;
        stack<string> st;
        while (getline(scin, word, '/')) {
            if (word == "" || word == ".") {
                continue;
            } else if (word == "..") {
                if (st.empty()) {
                    continue;
                }
                st.pop();
            } else {
                st.push(word);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (!ans.size()) {
            ans = "/";
        }
        return ans;
    }
};