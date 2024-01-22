#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int ans[n];
        for(int i=0;i<n;i++){
            cin>>ans[i];
        }
        int max;
        max=ans[0]+ans[n-1];
        for(int j=0;j<n-1;j++){
            int sum;
            sum=ans[j]+ans[j+1];
            if (sum>max){
                max=sum;
            }
        }
        cout<<max<<endl;
        t-=1;
    }
    return 0;
}