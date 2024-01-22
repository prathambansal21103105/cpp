#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;

    while(t>0){
        int n,k;
        cin>>n>>k;

        int index[n+1];
        vector<int>v;
        index[0]=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            index[x]=i;
        }
        int count1=0;
        for(int i=0;i<n;i++){
            if(index[i+1]>=index[i]){
                count1+=1;
            }
            else{
                break;
            }
        }
        if(count1==n){
            cout<<0<<endl;
        }
        else{
            int ans=(n-count1)/k;
            if((n-count1)%k!=0){
                ans+=1;
            }
            cout<<ans<<endl;
        }

        t-=1;
    }

    return 0;
}