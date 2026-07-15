class Solution {
public:
    bool isvalid(vector<int>&occur, vector<int>&real){
        for(int i=0 ; i<58 ; i++){
            if(occur[i] > real[i]){
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        string ans = "";
        int best = INT_MAX;
        if(t.size() > s.size()){
            return ans;
        }

        vector<int>occur(58, 0);

        for(auto ele:t){
            occur[ele - 'A']++;
        }

        vector<int>real(58, 0);

        int l=0, r=0;
        while(r < s.size()){
            while(r<s.size() && !isvalid(occur, real)){
                real[s[r] - 'A']++;
                r++;
            }

            while(isvalid(occur, real)){
                real[s[l] - 'A']--;
                l++;
            }
            
            if(l == 0){
                return ans;
            }

            if(best > r-l+2){
                best = r-l+2;
                ans = s.substr(l-1, r-l+1);
            }
        }        

        return ans;

    }
};