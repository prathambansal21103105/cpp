#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n,m;
        cin>>n>>m;

        vector<long long>a;
        vector<long long>b;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<m;i++){
            long long y;
            cin>>y;
            b.push_back(y);
        }
        sort(a.begin(),a.end());
        int count=0;
        while(count<m){
            a[0]=b[count];
            count+=1;
            sort(a.begin(),a.end());
        }
        long long sum1=0;
        for(int i=0;i<n;i++){
            sum1+=a[i];
        }
        cout<<sum1<<endl;
        t-=1;
    }
    return 0;
}

/*
4 2
1 3 7 9
2 4
*/