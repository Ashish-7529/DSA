class Solution {
public:
    string trim(string &s){
        size_t one = s.find('1');
        return one == -1 ? "0" : s.substr(one);
    }
    string addBinary(string a, string b) {
        a = trim(a);
        b = trim(b);
        int n = a.size();
        int m = b.size();

        if(n<m){
            swap(a,b);
            swap(n,m);
        }
        
        int carry = 0;
        int j = m-1;

        for(int i = n-1; i>=0; i--){
            int bit1 = a[i] - '0';
            int sum = bit1 + carry;

            if(j >= 0){
                int bit2 = b[j] - '0';
                sum += bit2;
                j--;
            }

            int bit = sum % 2;
            carry = sum / 2;
            a[i] = char(bit + '0');
        }
        if(carry>0){
            a = '1' + a;
        }
        return a;
    }
};