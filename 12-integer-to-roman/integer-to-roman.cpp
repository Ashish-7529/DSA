class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<string,int>> sym_val{
            {"M",1000},{"CM",900},{"D",500},{"CD",400},
            {"C",100},{"XC",90},{"L",50},{"XL",40},
            {"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}
        };
        string ans="";
        for(auto it:sym_val){
            string sym=it.first;
            int val=it.second;
            if(val==0) break;
            while(num>=val){
                ans+=sym;
                num-=val;
            }
        }
        return ans;
        
    }
};