class Solution {
public:
    bool sumGame(string num) {
        int lcount=0,rcount=0;
        int lsum=0,rsum=0;
        int n =num.size();
        for(int i=0,j=n-1; i<j; i++,j--){
            if(num[i] == '?')  lcount++;
            else    lsum += num[i]-'0';

            if(num[j] == '?')  rcount++;
            else    rsum += num[j]-'0';
        }
        
        
        if((lcount + rcount) % 2 == 1)  return true;
        int left = 2 * lsum + 9 * lcount;
        int right = 2 * rsum + 9 * rcount;
        if(left==right)
            return false;
        return true;
    }
};