class Solution {
public:
    bool isNumber(string s) {
        bool num = false, exp = false, sign = false, dec = false;
        for(int i = 0, n = s.length(); i < n; ++i){
            const char& ch = s[i];
            if(isdigit(ch)) num = true;
            else if(ch == 'e' || ch == 'E'){
                if(exp || !num) return false;
                else exp = true, num = false, sign = false, dec = false;
            }
            else if(ch == '+' || ch == '-'){
                if(sign || num || dec) return false;
                else sign = true;
            }
            else if(ch == '.'){
                if(dec || exp) return false;
                else dec = true;
            }
            else return false;
        }
        return num;
    }
};