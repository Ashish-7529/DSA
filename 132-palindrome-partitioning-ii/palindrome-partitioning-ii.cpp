class Solution {
public:

    bool checkPal(string &s)
    {
        int i = 0;
        int j = s.length()-1;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }

            else return false;
        }

        return true;
    }

    int solveRec(string &s, int index)
    {
        if(index>=s.length()) return 0;

        int ans = INT_MAX;
        for(int i=index;i<s.length();i++)
        {
            int curr = INT_MAX;
            string str = s.substr(index,i-index+1);
            if(checkPal(str) )
            {
                if(i==s.length()-1) curr = 0;
                else curr = 1 + solveRec(s,i+1);
            }
            ans = min(ans,curr);
        }

        return ans;
    }

    int solveMem(string &s, int index, vector<int> &dp, vector<vector<bool>> &pal)
    {
        if(index>=s.length()) return 0;

        if(dp[index]!=-1) return dp[index];

        int ans =INT_MAX;
        for(int i=index;i<s.length();i++)
        {
            int curr = INT_MAX;
            if(pal[index][i])
            {
                if(i==s.length()-1) curr = 0;
                else curr = 1 + solveMem(s,i+1,dp,pal);
            }
            ans = min(ans,curr);
        }

        return dp[index] = ans;
    }

    int solveTab(string &s, vector<vector<bool>> &pal)
    {
        int n = s.length();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            int ans = INT_MAX;
            for(int j=i;j<n;j++)
            {
                int curr = INT_MAX;
                if(pal[i][j])
                {
                    if(j==n-1) curr = 0;
                    else curr = 1 + dp[j+1];
                }
                ans = min(ans,curr);
            }

            dp[i] = ans;
        }

        return dp[0];
    }

    int minCut(string s) {
        //return solveRec(s,0);
        int n = s.length();
        //vector<int>dp(n,-1);
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) pal[i][i] = true;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<s.length();j++)
            {
                if(i==j) continue;
                if(s[i]==s[j]) 
                {
                    if(j-i>1) pal[i][j] = pal[i+1][j-1];
                    else pal[i][j] = true;
                }
            }
        }
        //return solveMem(s,0,dp,pal);

        return solveTab(s,pal);
    }
};