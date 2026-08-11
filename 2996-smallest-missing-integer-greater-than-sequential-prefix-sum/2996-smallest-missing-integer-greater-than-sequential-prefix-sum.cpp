class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],s=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                ans+=nums[i+1];
                s=i+1;
            }else{
                break;
            }
        }
        std::sort(nums.begin() + (s+1), nums.end());
        for(int i=s;i<n;i++){
            if(nums[i]==ans){
                ans++;
            }
        }
        return ans;
    }
};