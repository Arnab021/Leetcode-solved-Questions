class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr1;
        k=k%n;
        for(int i=n-k;i<n;i++){
            arr1.push_back(nums[i]);
        }
        nums.erase(nums.end()-k,nums.end());
        nums.insert(nums.begin(),arr1.begin(),arr1.end());
    }
};