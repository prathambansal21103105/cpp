#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a[n];
        int suma=0;
        int sumsub=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i];
            suma+=a[i];
            sumsub=max(sumsub,suma);
        }
        int m;
        cin>>m;
        int b[m];
        int bp=0;
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]>=0){
                bp+=b[i];
            }
        }
        suma=0;
        for(int i=n;i>=0;--i){
            suma+=a[i];
            sumsub=max(sumsub,suma);
        }
        cout<<sumsub+bp<<endl;
        t-=1;
    }
    return 0;
}