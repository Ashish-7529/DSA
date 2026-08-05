class Solution {
public:
    int sqsum(int n){
        int c=0;
        while(n){
            c += (n%10)*(n%10);
            n/=10;
        }
    return c;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        do{
            slow= sqsum(slow);
            fast = sqsum(sqsum(fast));
        } while(slow!=fast);
    return slow==1;
    }
};