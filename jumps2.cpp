int jump(vector<int>& nums) {
    int n=nums.size();
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    if(n==0 or n==1 or nums[0]==0){
        return 0;
    }
    dp[0]=0;
    int max=0;
    int jumps=1;
    for(int i=0;i<n;i++){
        int prev=max;
        int curr=i+nums[i];
        int flag=0;
        if(curr>max){
            // cout<<curr<<" "<<max<<endl;
            // cout<<"YES"<<endl;
            max=curr;
            jumps=1+dp[i];
            flag=1;
        }
        if(flag==0){
            continue;
        }
        else{
            int max=min(n-1,max);
            for(int j=prev+1;j<=max;j++){
                dp[j]=jumps;
            }
        }

    }
    // for(int i=1;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return dp[n-1];
}