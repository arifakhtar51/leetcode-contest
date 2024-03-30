class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n=p.size();
        vector<int>arr(n,0);
        arr[n-1]=p[n-1];
        if(p[n-1]==0){
            arr[n-1]=-1;
        }
        else arr[n-1]=1;
        
        for(int i=n-2;i>=0;i--){
            if(p[i]==1){
                arr[i]=arr[i+1]+p[i];
                
            }
            else {
                 arr[i]=arr[i+1]-1;
            }
        }
        int cnt=0;
        int sm=0;
        for(int i=0;i<n-1;i++){
            if(p[i]==1){
                sm++;
            }
            else sm--;
            int sm2=arr[i+1];
            cnt++;
            if(sm>sm2){
                return cnt;
            }
        }
        return -1;
        
    }
};