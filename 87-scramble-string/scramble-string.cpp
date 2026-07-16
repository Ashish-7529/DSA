class Solution {
public:
    unordered_map<string,int>mp;
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1.empty()&&s2.empty()) return true;
        if(s1==s2)return true;
        if(s1.length()<=1)return false;
        string key=s1;
        key.push_back(' ');
        key.append(s2);
        if(mp.find(key)!=mp.end()) return mp[key];
        int n=s1.size();
        bool flag=false;
        for(int i=1;i<n;i++){
            bool cond1=isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
            bool cond2=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            if(cond1 || cond2){
                flag=true;
                break;
            }
        }
        mp[key]=flag;
        return flag;
    }
};