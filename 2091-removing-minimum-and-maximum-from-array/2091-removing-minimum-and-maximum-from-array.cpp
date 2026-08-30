class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int min_index = 0;
        int max_index = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[min_index]){
                min_index = i;
            }
            if(nums[i] > nums[max_index]){
                max_index = i;
            }
        }

        if(min_index > max_index){
            swap(min_index,max_index);
        }

        int delete_front = max_index + 1;
        int delete_back = n - min_index;
        int delete_both = (min_index + 1) + (n - max_index);
        return min({delete_front, delete_back, delete_both});
    }
};