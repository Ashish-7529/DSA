class Solution {
public:
    int helper(vector<int>& nums,int n,vector<int>& memo){
        if(n==0){
            return nums[0];
        }
        if(n==1){
            return max(nums[0], nums[1]);
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        return memo[n]=max(helper(nums,n-2,memo)+nums[n],helper(nums,n-1,memo));
    }
    
    int rob(vector<int>& nums) {
        int max;
        vector<int> memo(nums.size()+1,-1);
        max=helper(nums,nums.size()-1,memo);
        return max;
    }
};