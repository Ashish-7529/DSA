class Solution {
public:

    int fact(int n, vector<int>& arr){

        if(n <= 1){
            return 1;
        }

        if(arr[n] != -1){
            return arr[n];
        }

        int x = fact(n-1,arr); 

        int y = fact(n-2,arr); 

        return arr[n] = x + y;
    }

    int climbStairs(int n) {
        
        vector<int> arr(n+1,-1);

        return fact(n,arr);
    }
};