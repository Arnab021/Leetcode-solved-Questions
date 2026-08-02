class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int arr[n];
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                arr[a++]=nums[i];
            }
        }
        arr[a++]=nums[n-1];
        for(int i=0;i<a;i++){
            nums[i]=arr[i];
        }
        return a;
    }
};