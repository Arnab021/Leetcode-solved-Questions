class Solution {
public:
    bool isPalindrome(int x) {
        long long ans=0;
        int a=x,rem;
        while(a!=0){
            rem=a%10;
            ans=ans*10+rem;
            a=a/10;
        }
        if(x==ans&&x>=0){
            return true;
        }else{
            return false;
        }
    }
};