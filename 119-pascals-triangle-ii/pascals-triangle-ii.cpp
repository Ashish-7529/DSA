class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        long long curr = 1; // Use long long to handle temporary big products

        for (int i = 0; i < rowIndex; i++) {
            // Multiply first to prevent integer division truncation
            curr = curr * (rowIndex - i) / (i + 1);
            row.push_back((int)curr);
        }

        return row;
    }
};