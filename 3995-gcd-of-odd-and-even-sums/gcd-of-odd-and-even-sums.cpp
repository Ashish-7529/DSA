class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum=0,evensum=0,gcd=1,i=1;
        int oddterm=1,eventerm=0;

        for (i=1;i<=n;i++){
            oddterm+=2;
            eventerm+=2;
            oddsum+= oddterm;
            evensum+= eventerm;

            if (oddsum%i ==0 && evensum%i==0){
                gcd=i;
            }
        }

        return gcd;
        
    }
};