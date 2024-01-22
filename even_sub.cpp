#include<bits/stdc++.h>
#include<vector>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin>>t;
    
    vector<long long>squares;
    for(int i=0;i*i<400000;i++){
        long long sq=i*i;
        squares.push_back(sq);
    }
    while(t>0){
        int n;
        cin>>n;
 
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        long long xors[400000]={0};
 
        long long prefixor[n];
        int xor1=0;
        for(int i=0;i<n;i++){
            xor1=v[i] xor xor1;
            prefixor[i]=xor1;
        }
        int count1=0;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<squares.size();j++){
                if(squares[j]>=2*n){
                    break;
                }
                int curr=prefixor[i];
                int p=curr xor squares[j];
                if(p<2*n){
                    count1+=xors[p];
                }
                if(p==0){
                    count1+=1;
                }
            }
            xors[prefixor[i]]++;
        }
 
        long long ans=n*(n+1)/2;
        ans-=count1;
        cout<<ans<<endl;
 
        t-=1;
    }
    return 0;
}
