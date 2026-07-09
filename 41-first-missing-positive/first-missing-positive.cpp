class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]>1 || nums[nums.size()-1]<0) return 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<0 && nums[i+1]>0 && nums[i+1]!=1) return 1;
            if(nums[i]>=0){
                if(nums[i+1]-nums[i]>1) return nums[i]+1;
            }
        }
        return nums[nums.size()-1]+1;
    }
};