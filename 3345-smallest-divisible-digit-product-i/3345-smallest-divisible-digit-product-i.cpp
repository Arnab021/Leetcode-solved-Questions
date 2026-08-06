class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int product=1;
            int m=n;
            while(m>0){
                product*=(m%10);
                m=m/10;
            }
            if(product%t==0){
                return n;
            }else{
                n++;
            }
        }
    }
};