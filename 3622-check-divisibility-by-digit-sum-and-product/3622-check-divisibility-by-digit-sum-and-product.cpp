class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int k=n;
        while(k!=0){
            int rem=k%10;
            sum+=rem;
            product*=rem;
            k=k/10;
        }
        if(n%(sum+product)==0){
            return true;
        }
        return false;
    }
};