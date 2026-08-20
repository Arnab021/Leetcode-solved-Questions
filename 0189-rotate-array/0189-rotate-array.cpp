class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        k=k%n;
        for(int i=0;i<n-k;i++){
            arr1.push_back(nums[i]);
        } 
        for(int i=n-k;i<n;i++){
            arr2.push_back(nums[i]);
        }
        arr2.insert(arr2.end(),arr1.begin(),arr1.end());
        nums=arr2;
    }
};