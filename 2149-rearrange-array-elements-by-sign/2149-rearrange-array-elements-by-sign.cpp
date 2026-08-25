class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n);
        int l = 0,r = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[l] = nums[i];
                l += 2;
            } else {
                ans[r] = nums[i];
                r += 2;
            }
        }
        return ans;
    }
};