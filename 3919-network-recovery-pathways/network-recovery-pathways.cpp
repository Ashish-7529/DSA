class Solution {
public:
    bool
    isThisMidAValidSolution(int mid,
                            unordered_map<int, vector<pair<int, int>>>& mpp,
                            vector<bool>& online, int n, long long k) {
        vector<long long> res(n + 1, LLONG_MAX);
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>> pq;

        pq.push({0, 0});
        res[0] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (online[node] == 0)
                continue;

            if (cost > k)
                return false;

            if (node == n - 1)
                return true;

            if (res[node] < cost)
                continue;

            for (auto& it : mpp[node]) {
                int nei = it.first;
                int wt = it.second;

                if (wt < mid)
                    continue;

                if (!online[nei] && nei != n - 1)
                    continue;

                if (cost + wt < res[nei]) {
                    res[nei] = cost + wt;
                    pq.push({cost + wt, nei});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        unordered_map<int, vector<pair<int, int>>> mpp;
        int mx = 0;

        for (auto& e : edges) {
            mpp[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        int n = online.size();
        int lo = 0, hi = mx;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isThisMidAValidSolution(mid, mpp, online, n, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};