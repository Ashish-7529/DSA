class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char , int> map ; 
        int i = 0 ; 
        int max_length = 0 ; 

        for (int j = 0 ; j < s.length() ; j++){
            if (map.contains(s[j])){
                max_length = max(max_length  , map[s[j]] + 1) ; 
            }
            map[s[j]] = j; 
            i = max(i , (j-max_length) + 1) ; 
        }

        return i ; 
    }
};