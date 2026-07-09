class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<int> current;
        backtrack(candidates, current, target, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int>& current, int target, int sum, int index) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        
        int n = candidates.size();
        for (int i = index; i < n; i++) {
            if (sum + candidates[i] > target)
                return;
            
            current.push_back(candidates[i]);
            backtrack(candidates, current, target, sum + candidates[i], i);
            current.pop_back();
        }
    }
};