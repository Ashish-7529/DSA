class Solution {
public:
    void solve(int ind,set<vector<int>> &st,vector<int> &v,vector<int> &nums,int n){
        if(ind == n){
            st.insert(v);
            return;
        }
        st.insert(v);

        solve(ind+1,st,v,nums,n);

        v.push_back(nums[ind]);
        solve(ind+1,st,v,nums,n);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>v;
        int n = nums.size();

        solve(0,st,v,nums,n);

        vector<vector<int>>ans;

        for(auto i:st){
            ans.push_back(i);
        }

        return ans;
    }
};