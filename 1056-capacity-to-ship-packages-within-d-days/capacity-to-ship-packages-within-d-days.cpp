int reqdays(vector<int>& weights, int val){
    int day=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>val)
        {
            day+=1;
            load=weights[i];
        }
        else load+=weights[i];
    }
    return day;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int low=maxi,high=sum,ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(reqdays(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};