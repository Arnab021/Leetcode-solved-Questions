class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0){
            int m=n;
            int i=-1;
            while(n!=0){
                n=n/2;
                i++;
            }
            int ans=pow(2,i);
            return ans==m;
        }else{
            return false;
        }
    }
};