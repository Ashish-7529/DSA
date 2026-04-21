bool possible(vector<int>& bloomDay, int m, int k,int val){
    int cnt=0,totalbou=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=val) cnt++;
        else{
            totalbou+=(cnt/k);
            cnt=0;
        }
    }
    totalbou+=cnt/k;
    if(totalbou>=m) return true;
    else return false;
}
int maxele(vector<int>& piles){
    int ans=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        ans=max(ans,piles[i]);
    }
    return ans;
}
int minele(vector<int>& piles){
    int ans=INT_MAX;
    for(int i=0;i<piles.size();i++)
    {
        ans=min(ans,piles[i]);
    }
    return ans;
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=minele(bloomDay),high=maxele(bloomDay);
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)){
                
                high=mid-1;

            }
            else low=mid+1;
        }
        return low;
    }
};