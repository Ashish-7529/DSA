class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0; 
        
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            if(maxi == 0 && i != nums.size() - 1) return false;
            maxi--; 
            
        }
        return true;

    }
};