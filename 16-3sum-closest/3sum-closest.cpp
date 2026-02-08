class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left,right;
        int closestsum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            left=i+1;
            right=nums.size()-1;
            while(left<right)
            {
                int currentsum=nums[i]+nums[left]+nums[right];
                if(abs(currentsum-target)<abs(closestsum-target))
                {
                    closestsum=currentsum;
                }
                else if(currentsum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return closestsum;
        
    }
};