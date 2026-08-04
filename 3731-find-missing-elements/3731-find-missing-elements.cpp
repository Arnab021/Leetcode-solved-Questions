class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                }

            }
        }
        for(int i=0;i<n-1;i++){
            int s=nums[i];
            while(nums[i+1]-s!=1){
                arr.push_back(s+1);
                s++;
            }
        }
        return arr;

    }
};