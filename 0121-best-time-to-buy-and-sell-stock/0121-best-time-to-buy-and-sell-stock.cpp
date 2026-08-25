class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_price=0;
        int left=0,right=1;
        while(left<right && right<n){
            if(prices[right]-prices[left]>0){
                max_price=max(max_price,prices[right]-prices[left]);
                right++;
            }
            else{
                left = right;
                right++;
            }
        }
        return max_price;
    }
};