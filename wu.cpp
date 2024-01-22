#include<iostream>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;

int bd(string s1){
    int ans=0;
    int num=1;
    for(int i=s1.length()-1;i>=0;i--){
        if(s1[i]=='1'){
            ans+=num;
        }
        num*=2;
    }
    return ans;
}

int main(){

    int n,m,q;
    cin>>n>>m>>q;

    vector<int>wi;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        wi.push_back(x);
    }
    unordered_map<int,int>s1;
    for(int i=0;i<m;i++){
        string si;
        cin>>si;
        int x=bd(si);
        if(s1.count(x)!=0){
            s1[x]+=1;
        }
        else{
            s1[x]=1;
        }
    }

    vector<int>t1;
    vector<int>k;
    for(int i=0;i<q;i++){
        string ti;
        cin>>ti;
        int x=bd(ti);
        t1.push_back(x);

        int ki;
        cin>>ki;
        k.push_back(ki);
    }

    unordered_map<int,int>amap;
    int x=1<<n;
    x=x-1;
    for(int i=0;i<=x;i++){
        int sum1=0;
        for(int j=0;j<=n-1;j++){
            int k=n-1-j;
            int y=1<<k;
            if((i&y)==0){
                sum1+=wi[j];
            }
        }
        amap[i]=sum1;
    }

    for(int i=0;i<q;i++){
        int count1=0;
        for(int j=0;j<=x;j++){
            if(amap[j]<=k[i]){
                int r=t1[i] ^ j;
                if(s1.count(r)!=0){
                    count1+=s1[r];
                }
            }
        }
        cout<<count1<<endl;
    }

    return 0;
}

/*
// void solve(int n, int m, int q, vector<int>wi, vector<string>s, vector<string>t, vector<int>k){

//     for(int i=0;i<q;i++){
//         int count=0;
//         for(int j=0;j<m;j++){
//             int sum1=0;
//             for(int r=0;r<n;r++){
//                 if(t[i][r]==s[j][r]){
//                     sum1+=wi[r];
//                 }
//             }
//             if(sum1<=k[i]){
//                 count+=1;
//             }
//         }
//         cout<<count<<endl;
//     }
// }
*/