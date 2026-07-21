class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> left(n),right(n);
        int cnt=0;
        for(int i=0;i<n;i++){
           if(s[i]=='0'){
            cnt++;
            left[i]=cnt;
           }
           else {
            left[i]=cnt;
            cnt=0;
           }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
            cnt++;
            right[i]=cnt;
           }
           else {
            right[i]=cnt;
            cnt=0;
           }
        }
        cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') continue;
            int j=i;
            while(j<n && s[j]!='0' ){
                j++;
                cnt++;
            }
            if(left[i]>0 && right[j-1]>0){
                ans=max(left[i]+right[j-1],ans);
            }
            i=j-1;
        }
        return cnt+ans;
    }
};