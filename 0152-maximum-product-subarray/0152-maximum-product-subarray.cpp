class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_pro=INT_MIN;
        int ans = 1;
        for(int i=0;i<n;i++){
            ans = ans * nums[i];
            max_pro = max(max_pro, ans);
            if(ans == 0) {
                ans = 1;
            }
        }
        ans = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans = ans * nums[i];
            max_pro = max(max_pro, ans);
            
            if(ans == 0) {
                ans = 1;
            }
        }
        return max_pro;
    }
};