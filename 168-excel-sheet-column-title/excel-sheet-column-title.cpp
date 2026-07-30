class Solution {
public:
    string convertToTitle(int columnNumber) {
        int first=columnNumber;
        string ans="";

        while(first>26){
            first--;
            int second=first%26;
            ans.push_back(second+'A');
            first=first/26;
        }
        ans.push_back(first-1+'A');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};