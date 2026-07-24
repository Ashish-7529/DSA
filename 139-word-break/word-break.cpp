class Solution {
public:
   int dp[300];
   bool f(int index , string s, vector<string>& wordDict){
    if(index == s.size()) return true;
    if(dp[index] != -1){
        return dp[index];
    }
    bool ways = false;
    for(int i=0;i<wordDict.size();i++){
        if(s.substr(index ,wordDict[i].size()) == wordDict[i]){
           ways |= f(index+ wordDict[i].size() , s, wordDict);
        }
    }
    dp[index] =ways;
    return dp[index];
   }
    bool wordBreak(string s, vector<string>& wordDict) {
       memset(dp , -1 , sizeof(dp));
       return f(0 , s, wordDict);
    }
};