class Solution {
public:
    int divide(int a, int b) {
        long long x = b, y = a, sum = 0;
        bool is = false;

        if (y == INT_MIN && x == -1) return INT_MAX;
        if (y == INT_MIN && x ==  1) return INT_MIN;

        if (x < 0 && y > 0) { x = -x; is = true; }
        else if (y < 0 && x > 0) { y = -y; is = true; }
        else if (x < 0 && y < 0) { x = -x; y = -y; }

        if (y == 0 || x == 0) return 0;
        if (x == 1) return is ? -y : y;

        long long reminder = y;

        while (reminder >= x) {
            long long temp = x;
            long long count = 1;
            while ((temp << 1) <= reminder) {
                temp <<= 1;
                count <<= 1;
            }
            sum += count;
            reminder -= temp;
        }

        if (is) sum = -sum;
        if (sum > INT_MAX) return INT_MAX;
        if (sum < INT_MIN) return INT_MIN;

        return (int)sum;
    }
};