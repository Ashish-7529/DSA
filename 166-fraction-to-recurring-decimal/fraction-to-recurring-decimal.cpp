class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;

        if (numerator == 0)
            return "0";
        if (1LL * numerator * denominator < 0)
            res += "-";

        long long num = labs((long long)numerator);
        long long den = labs((long long)denominator);

        long long q = (num) / (den);
        long long rem = num % den;
        res += to_string(q);
        if (rem == 0)
            return res;

        res += ".";

        unordered_map<long long, long long> mp;

        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }

            mp[rem] = res.size();
            
            rem *= 10;
            long long quotient = rem / den;
            res += to_string(quotient);
            rem = rem % den;
        }
        return res;
    }
};