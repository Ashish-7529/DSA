class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>vis(n);
        for(int i=0;i<invocations.size();i++){
            int a=invocations[i][0];
            int b=invocations[i][1];
            vis[a].push_back(b);
        }
        vector<int>dp(n,0);
        dp[k]=1;
        queue<int>q;
        q.push(k);
        //it will visit all the affected groups.
        while(!q.empty()){
            int h=q.front();
            q.pop();
            for(auto it:vis[h]){
                if(dp[it]!=1){
                    dp[it]=1;
                    q.push(it);
                }
            }
        }

        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                for(auto it:vis[i]){
                    if(dp[it] == 1){
                        c+=1;
                        break;
                    }
                }
            }
        }

        vector<int>r;
        if(c==0){
            for(int i=0;i<n;i++){
                if(dp[i]!=1){
                    r.push_back(i);
                }
            }
        }else{
            for(int i=0;i<n;i++){
                r.push_back(i);
            }
        }

        return r;
    }
};