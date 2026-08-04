class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> arr;
        for(int i=0;i<n1;i++){
            arr.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            arr.push_back(nums2[i]);
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        float ans;
        if(n%2==0){
            int a=n/2;
            int b=a-1;
            ans=(arr[a]+arr[b])/2.0;
        }else{
            ans=arr[n/2];
        }
        return ans;
    }
};