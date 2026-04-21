int maxele(vector<int>& piles){
    int ans=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        ans=max(ans,piles[i]);
    }
    return ans;
}
double total(vector<int>& piles, int k){
    double tot=0;
    for(int i=0;i<piles.size();i++){
        tot+=ceil((double)piles[i]/(double)k);
    }
    return tot;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high = maxele(piles),ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(total(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;    
    }
};