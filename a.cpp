class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int ele=0;
            for(int j=i;j<n;j++){
                ele|=nums[j];
                if(ele>=k){
                    ans=min(ans,j-i+1);
                }
            }
            // cout<<xr<<" ";
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};