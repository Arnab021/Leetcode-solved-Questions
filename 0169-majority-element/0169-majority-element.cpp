class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size()/2;
        for(auto it:nums){
            mp[it]++;

            if(mp[it]>n){
                return it;
            }
        }
        
        return 0;
    }
};