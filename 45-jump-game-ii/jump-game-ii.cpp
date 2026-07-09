class Solution {
public:
    int func(int index, vector<int>& memo, vector<int>& arr){
        if(index >= arr.size()-1) return 0;
        if (memo[index] != -1) return memo[index];
        
        int mini = 1e9;
        for(int i = 1 ; i <= arr[index]; i++){
            mini = min(mini, 1 + func(index + i, memo, arr)); 
        }
        return memo[index] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return func(0, memo, nums); 
    }
};