#include<iostream>
using namespace std;
void arrange(int arr[],int n){
    int nodds=0;
    int neven=0;
    if (n%2==0){
        neven=n/2;
        nodds=n/2;
    }
    else{
        neven=n/2;
        nodds=int(n/2)+1;
    }
    for(int i=0;i<nodds;i++){
        arr[i]=(2*i)+1;
    }
    int j=0;
    for(int i=nodds;i<n;i++){
        arr[i]=2*(neven-j);
        j++;
    }

}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            ar[i]=i+1;
        }
        arrange(ar,n);
        t-=1;
    }
    return 0;
}