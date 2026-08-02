class Solution {
public:
    bool check(vector<int>& nums) {
        int n =nums.size();
        int s=0;
        for(int i=0;i<n;++i){
            if(nums[i]>nums[(i+1)%n]){
                s++;
            }
        }
        return s<=1;
    }
};