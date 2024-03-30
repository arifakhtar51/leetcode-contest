class Solution {
public:
    int binaryStringToInt(vector<int>& b) {
   int result = 0;
    for(int i=0;i<b.size();i++){
        if(b[i]>=1){
            result+=(1<<i);
        }
    }
        return result;
}
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>freq(33,0);
        int i=0,j=0;
        int n=nums.size();
        int xr=0;
        int ans=INT_MAX;
        bool flag=0;
        while(j<n){
           string bin= bitset<32>(nums[j]).to_string();
            xr|=nums[j];
            reverse(begin(bin),end(bin));
            for(int i=0;i<32;i++){
                if(bin[i]=='1'){
                    freq[i]++;
                }
            }
            // for(auto k:freq){
            //             cout<<k<<" ";
            // }
            // cout<<endl;
            if(xr>=k){
                // cout<<xr<<" ";
                flag=1;
                ans=min(ans,j-i+1);
                while(i<j){
                    string bi= bitset<32>(nums[i]).to_string();
                    reverse(begin(bi),end(bi));
                    for(int i=0;i<32;i++){
                        if(bi[i]=='1'){
                            freq[i]--;
                        }
                    }
                    int num=binaryStringToInt(freq);
                    if(num>=k){
                        i++;
                          ans=min(ans,j-i+1);
                        xr=num;
                        continue;
                    }
                    else {i++;break;}
                }
               
            }
            j++;
            
        }
        if(flag==0)return -1;
        return ans;
    }
};