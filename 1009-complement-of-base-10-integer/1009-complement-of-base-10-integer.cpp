class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        int i=0;
        if(n>0){
            while(n!=0){
                int r=n%2;
                if(r==1){
                    r=0;
                    ans=ans+r*pow(2,i);
                }else{
                    r=1;
                    ans=ans+r*pow(2,i);
                }
                i++;
                n=n/2;
            }
        }else{
            ans=1;
        }
        return ans;
    }
};