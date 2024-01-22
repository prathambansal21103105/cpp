#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve(int n, int l, int u, int d, vector<int>v){
    int x=(1<<n);
    x=x-1;

    int count=0;
    for(int i=0;i<=x;i++){
        int sum1=0;
        int flag=0;
        int lowest=0;
        int highest=0;
        for(int j=0;j<=n-1;j++){
            int k=n-1-j;
            int y=1<<k;
            if((y&i)==0){
                continue;
            }
            else{
                if(flag==0){
                    lowest=v[j];
                    flag=1;
                }
                highest=v[j];
                sum1+=v[j];
            }
        }
        if(sum1>=l and sum1<=u and d<=highest-lowest){
            count+=1;
        }
    }
    cout<<count<<endl;
}


int main(){
    int n,l,u,d;
    cin>>n>>l>>u>>d;
    
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    solve(n,l,u,d,v);

    return 0;
}