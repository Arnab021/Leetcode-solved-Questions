class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)  return 1;

        int minvalue = *min_element(nums.begin(), nums.end());
        int maxvalue = *max_element(nums.begin(), nums.end());

        int minindex, maxindex;
        for(int i=0; i<n; i++){
            if(nums[i] == minvalue) minindex = i;
            if(nums[i] == maxvalue) maxindex = i;
        }

        if (minindex > maxindex) {
            swap(maxindex, minindex);
        }

        int delete_both_from_left  = maxindex + 1;
        int delete_both_from_right = n - minindex;
        int delete_from_both_sides = (minindex + 1) + (n - maxindex);

        return min({delete_both_from_left, delete_both_from_right, delete_from_both_sides});
    }
};