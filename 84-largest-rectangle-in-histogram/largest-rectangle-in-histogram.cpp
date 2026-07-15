class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<pair<int, int>> nsl; // we use this stack to findout nearest smaller to left  (NSL)
        vector<int> left(n);

        stack<pair<int, int>> nsr; // we use this stack to findout nearest smaller to right (NSR)
        vector<int> right(n);

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            // finding NSL
            while (!nsl.empty() && nsl.top().first >= heights[i]) {
                nsl.pop();
            }
            if (!nsl.empty()) {
                left[i] = nsl.top().second;
            }
            else {
                left[i] = -1;
            }
            nsl.push({heights[i], i});

            // finding NSR
            while (!nsr.empty() && nsr.top().first >= heights[n - 1 - i]) {
                nsr.pop();
            }
            if (!nsr.empty()) {
                right[n - 1 - i] = nsr.top().second;
            }
            else {
                right[n - 1 - i] = n;
            }
            nsr.push({heights[n - 1 - i], n - 1 - i});
        }

        for (int i = 0; i < n; i++) {
            // calculating width
            int width = right[i] - left[i] - 1;

            // calculating area
            int area = heights[i] * width;

         
            max_area = max(max_area, area);
        }

        return max_area;
    }
};