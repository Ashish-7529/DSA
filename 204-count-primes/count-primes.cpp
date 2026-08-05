class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<int> arr(n+1, -1);
        int count = 0, i;
        for (i = 2; i * i < n; i++) {
            if (arr[i] != -1)
                continue;
            arr[i] = i;
            count++;
            for (int k = i * i; k < n; k += i)
                arr[k] = k;
        }

        for (; i < n; i++)
            if (arr[i] == -1)
                count++;
        return count;
    }
};