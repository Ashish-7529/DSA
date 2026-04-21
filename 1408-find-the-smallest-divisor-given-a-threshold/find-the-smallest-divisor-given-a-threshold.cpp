int div(vector<int>& nums,int val){
    int tot=0;
    for(int i=0;i<nums.size();i++){
        tot+=ceil((double)nums[i]/(double)val);
    }
    return tot;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int low=1,high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(div(nums,mid)<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};